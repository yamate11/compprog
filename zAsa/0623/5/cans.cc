#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(unordered_map debug)

// ---- inserted library file unordered_map.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#if !defined(__TEMPLATE_SAFE_CUSTOM_HASH__)
#define __TEMPLATE_SAFE_CUSTOM_HASH__
template <typename T, typename Enable = void>
struct safe_custom_hash;
#endif

// For integer types (int, ll, u64, unsigned, ....)
template <typename T>
struct safe_custom_hash<T, typename enable_if<is_integral<T>::value>::type> {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// For string
template <>
struct safe_custom_hash<string, void> {
  static uint64_t mix(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }

  size_t operator()(const string& s) const {
    static const uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
    uint64_t h = seed ^ 0x9e3779b97f4a7c15ULL;
    const unsigned char* p = (const unsigned char*)s.data();
    size_t n = s.size();
    while (n >= 8) {
      uint64_t v;
      memcpy(&v, p, 8);
      h = mix(h ^ v);
      p += 8; n -= 8;
    }
    uint64_t tail = 0;
    for (size_t i = 0; i < n; ++i) tail |= uint64_t(p[i]) << (8*i);
    h = mix(h ^ tail);
    return (size_t)h;
  }
};

// For pair
template <typename T1, typename T2>
struct safe_custom_hash<pair<T1, T2>, void> {
  size_t operator()(const pair<T1, T2>& x) const {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
    static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
    return a * safe_custom_hash<T1>{}(x.first) + b * safe_custom_hash<T2>{}(x.second);
  }
};

// For tuple
template <typename... Ts>
struct safe_custom_hash<tuple<Ts...>, void> {
  size_t operator()(const tuple<Ts...>& x) const { return impl(x, index_sequence_for<Ts...>{}); }
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  template <size_t... Is>
  static size_t impl(const tuple<Ts...>& x, index_sequence<Is...>) {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const array<uint64_t, sizeof...(Ts)> coef = { (splitmix64(frand + Is) | 1)... };
    uint64_t h = 0;
    (
      void( h += coef[Is] * uint64_t(safe_custom_hash<tuple_element_t<Is, tuple<Ts...>>>{}(get<Is>(x))) ),
      ...
    );
    return h;
  }
};

template <typename T_key, typename T_value, bool useGP = false>
using safe_umap = conditional_t<useGP, gp_hash_table<T_key, T_value, safe_custom_hash<T_key>>,
                                unordered_map<T_key, T_value, safe_custom_hash<T_key>>>;
template <typename T_key, bool useGP = false>
using safe_uset = conditional_t<useGP, gp_hash_table<T_key, null_type, safe_custom_hash<T_key>>,
                                unordered_set<T_key, safe_custom_hash<T_key>>>;
template <typename T_key>
using safe_umultiset = unordered_multiset<T_key, safe_custom_hash<T_key>>;


// ---- end unordered_map.cc

// ---- inserted function f:<< from util.cc


// If a struct T has member function "string show() const",
// (1) operator<< is defined
// (2) g_show(const T&) is defined.
// g_show is also defined for integral and floating point types and string.


// Declartion of g_show

// If T has member function show(), it is used:

template<typename T>
concept HasShow = requires(const T& t) {
  { t.show() } -> convertible_to<string>;
};

template<class T>
concept Streamable = requires(ostream& os, const T& x) {
  os << x;
};

//   The declaration must be put before calling it.

template<class T>
string g_show(const T& x);

// Definition of g_show_impl
//    The separation between g_show and g_show_impl is needed for order independence.

template<HasShow T> string g_show_impl(const T& t) { return t.show(); }

// basic types

inline string g_show_impl(char c) { return string(1, c); }
inline string g_show_impl(const char* s) { return s ? string(s) : string("(null)"); }
inline string g_show_impl(bool b) { return b ? "true" : "false"; }

// int, ll, ...; note that this also is applied to "sigend/unsigned char"
template<integral T>
  requires (not same_as<T, bool> and not same_as<T, char>)
string g_show_impl(T t) { return to_string(t); }

// double, long double, ...
template<floating_point T> string g_show_impl(T t) { return to_string(t); }

// containers in the standard library

//    pair
template <typename T1, typename T2>
string g_show_impl(const pair<T1,T2>& p) { return "(" + g_show(p.first) + ", " + g_show(p.second) + ")"; }

//    tuple
template<class... Ts>
string g_show_impl(const tuple<Ts...>& t) {
  string s = "(";
  bool first = true;
  apply([&](const auto&... xs) {
    ((s += (first ? "" : ", "), first = false, s += g_show(xs)),
     ...);
  }, t);
  s += ")";
  return s;
}

//   vector, array, deque, (un)ordered set, multiset, (un)ordered map, 

template<typename T, bool pair=false>
string g_show_with_iterator(const T& v) {
  string ret = "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) ret += ", ";
    if constexpr (pair) ret += "(" + g_show(it->first) + ": " + g_show(it->second) + ")";
    else                ret += g_show(*it);
  }
  ret += "]";
  return ret;
}

template<typename T>
string g_show_impl(const vector<T>& v) { return g_show_with_iterator(v); }

template <typename T, size_t N>
string g_show_impl(const array<T, N>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const unordered_set<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename C>
string g_show_impl(const multiset<T, C>& v) { return g_show_with_iterator(v); }

template <typename T, typename T2>
string g_show_impl(const deque<T, T2>& v) { return g_show_with_iterator(v); }

template <typename T1, typename T2, typename C>
string g_show_impl(const map<T1, T2, C>& v) {
  return g_show_with_iterator<map<T1, T2, C>, true>(v);
}

template <typename T1, typename T2, typename C>
string g_show_impl(const unordered_map<T1, T2, C>& v) {
  return g_show_with_iterator<unordered_map<T1, T2, C>, true>(v);
}

//   queue, priority-queue

template<typename T>
string g_show_queue_and_like(const T& v0, auto front_like) {
  T v = v0;  // copy
  string ret = "[";
  bool first = true;
  while (not v.empty()) {
    if (not first) ret += ", ";
    first = false;
    const auto& x = front_like(v);
    ret += g_show(x);
    v.pop();
  }
  ret += "]";
  return ret;
}

template <typename T, typename T2>
string g_show_impl(const queue<T, T2>& v) {
  return g_show_queue_and_like(v, [](const queue<T, T2>& vv) { return vv.front(); });
}

template <typename T, typename T2, typename T3>
string g_show_impl(const priority_queue<T, T2, T3>& v) {
  return g_show_queue_and_like(v, [](const priority_queue<T, T2, T3>& vv) { return vv.top(); });
}

//    optional
template <typename T>
string g_show_impl(const optional<T>& t) { return t ? g_show(*t) : "(nullopt)"; }

//    (signed/unsigned) __int128
//    operator<< is defined here, and the next section makes g_show

ostream& operator<<(ostream& ostr, unsigned __int128 x) {
  if (x == 0) return ostr << "0";
  string s;
  while (x > 0) {
    int d = x % 10;
    s.push_back('0' + d);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return ostr << s;
}

ostream& operator<<(ostream& ostr, __int128 x) {
  if (x >= 0) {
    return ostr << (unsigned __int128)x;
  } else {
    unsigned __int128 ux = (unsigned __int128)x;
    ux = ~ux + 1;
    return ostr << "-" << ux;
  }
}

template<class T>
string g_show(const T& x) {
  if constexpr (requires { g_show_impl(x); }) {
    return g_show_impl(x);
  } else if constexpr (Streamable<T> && (not HasShow<T>)) {
    ostringstream oss;
    oss << x;
    return oss.str();
  }else {
    static_assert(sizeof(T) == 0, "g_show: unsupported type");
  }
}

// HasGShow
template<typename T>
concept HasGShow = requires(const T& t) {
  { g_show(t) } -> convertible_to<string>;
};

// ---- end f:<<

// ---- inserted library file debug.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/debug.cc
// https://github.com/yamate11/compprog-clib/blob/master/debug.cc

template<class T>
void dbgPrintOne(const T& x) {
  if constexpr (HasGShow<T>) {
    cerr << g_show(x);
  } else {
    cerr << x;
  }
}

inline void dbgLog(bool with_nl) {
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail) {
  dbgPrintOne(head);
  if constexpr (sizeof...(tail) > 0) {
    cerr << " ";
    dbgLog(with_nl, forward<Tail>(tail)...);
  } else {
    if (with_nl) cerr << endl;
  }
}

string dbgTrim(string s) {
  int l = 0, r = (int)s.size();
  while (l < r && isspace((unsigned char)s[l])) l++;
  while (l < r && isspace((unsigned char)s[r - 1])) r--;
  return s.substr(l, r - l);
}

vector<string> dbgSplitNames(const string& s) {
  vector<string> res;
  string cur;
  int depth = 0;

  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;

    if (c == ',' && depth == 0) {
      res.push_back(dbgTrim(cur));
      cur.clear();
    } else {
      cur += c;
    }
  }

  res.push_back(dbgTrim(cur));
  return res;
}

template<class T>
void dbgLogKOne(const string& name, T&& value) {
  cerr << name << "=";
  dbgPrintOne(forward<T>(value));
}

template<class... Args>
void dbgLogK(const char* names_c, Args&&... args) {
  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?= ";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

template<class Label, class... Args>
void dbgLogKL(Label&& label, const char* names_c, Args&&... args) {
  dbgPrintOne(forward<Label>(label));
  if constexpr (sizeof...(Args) > 0) cerr << " ";

  vector<string> names = dbgSplitNames(names_c);

  int idx = 0;
  auto print_one = [&](auto&& x) {
    if (idx > 0) cerr << " ";
    if (idx < (int)names.size()) {
      dbgLogKOne(names[idx], forward<decltype(x)>(x));
    } else {
      cerr << "?=";
      dbgPrintOne(forward<decltype(x)>(x));
    }
    idx++;
  };

  (print_one(forward<Args>(args)), ...);
  cerr << endl;
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DCALL(func, ...) func(__VA_ARGS__)
  #define DLOGK(...)       dbgLogK(#__VA_ARGS__, __VA_ARGS__)
  #define DLOGKL(lab, ...) dbgLogKL(lab, #__VA_ARGS__, __VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DCALL(func, ...)
  #define DLOGK(...)
  #define DLOGKL(lab, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [TpFDFwr8]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [TpFDFwr8]
  // @InpVec(N, B) [ayLqPwmH]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [ayLqPwmH]
  // @InpVec(N, C) [3Xn7thEc]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [3Xn7thEc]
  ranges::sort(A, greater<ll>());
  ranges::sort(B, greater<ll>());
  ranges::sort(C, greater<ll>());
  using sta = tuple<ll, ll, ll, ll>;
  priority_queue<sta> pque;
  auto f = [&](ll a, ll b, ll c) -> ll { return A[a] * B[b] + B[b] * C[c] + C[c] * A[a]; };
  using stb = tuple<ll, ll, ll>;
  safe_uset<stb> seen;
  auto op = [&](ll a, ll b, ll c) -> void {
    if (a >= N or b >= N or c >= N) return;
    if (not seen.contains(stb{a, b, c})) {
      seen.emplace(a, b, c);
      pque.emplace(f(a, b, c), a, b, c);
    }
  };
  op(0, 0, 0);
  ll cnt = 0;
  while (true) {
    DLOGK(pque);
    auto [v, a, b, c] = pque.top(); pque.pop();
    cnt++;
    if (cnt == K) {
      cout << v << endl;
      return 0;
    }
    op(a + 1, b, c);
    op(a, b + 1, c);
    op(a, b, c + 1);
  }

  return 0;
}

