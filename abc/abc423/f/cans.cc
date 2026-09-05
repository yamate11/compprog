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

// @@ !! LIM(fastTransform debug)

// ---- inserted library file fastTransform.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/fastTransform.cc

template <typename T>
int trans_resize(vector<T>& x, vector<T>& y) {
  int n = max(x.size(), y.size());
  int p = 31 - __builtin_clz(n);
  int t = 1 << p;
  if (n > t) t *= 2;
  x.resize(t);
  y.resize(t);
  return t;
}

template<typename T>
int trans_resize(vector<T>& x) { return trans_resize(x, x); }

template<typename T, int p1, int p2, int p3, int p4, int div>
void _trans_form(vector<T>& f) {
  int n = f.size();
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j];
        T y = f[j | i];
        f[j    ] = (p1 * x + p2 * y) / div;
        f[j | i] = (p3 * x + p4 * y) / div;
      }
    }
  }
}

template <typename T>
void hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 1>(f); }

template <typename T>
void inv_hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 2>(f); }

template<bool IS_LOWER, bool IS_ZETA>
void gen_zeta(auto& vec) {
  int n = countr_zero(vec.size());
  assert(ssize(vec) == (1LL << n));
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < ssize(vec); x++) {
      if ((x >> i & 1) == IS_LOWER) { vec[x] += (IS_ZETA ? 1 : -1) * vec[x ^ 1LL << i]; }
    }
  }
}
void zeta_lower(   auto& vec) { return gen_zeta<true,  true >(vec); }
void moebius_lower(auto& vec) { return gen_zeta<true,  false>(vec); }
void zeta_upper(   auto& vec) { return gen_zeta<false, true >(vec); }
void moebius_upper(auto& vec) { return gen_zeta<false, false>(vec); }

template<typename T>
void _conv_dest_form(vector<T>& x, vector<T>& y,
                     void fwd(vector<T>&), void bwd(vector<T>&)) {
  int t = trans_resize(x, y);
  fwd(x);
  fwd(y);
  for (int i = 0; i < t; i++) x[i] *= y[i];
  bwd(x);
}

template<typename T>
void xor_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, hadamard, inv_hadamard);
}

template<typename T>
void and_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_upper, moebius_upper);
}

template<typename T>
void or_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_lower, moebius_lower);
}

template <typename T>
vector<T> xor_conv(vector<T> x, vector<T> y) {
  xor_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> and_conv(vector<T> x, vector<T> y) {
  and_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> or_conv(vector<T> x, vector<T> y) {
  or_conv_dest(x, y);
  return x;
}

// ---- end fastTransform.cc

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

  ll N, M, Y; cin >> N >> M >> Y;
  // @InpVec(N, A) [imSdd3us]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [imSdd3us]

  vector<ll> L(1LL << N);
  vector<ll> G(1LL << N);
  L[0] = 1;
  REP(x, 0, 1LL << N) {
    ll i0 = bit_width((u64)x);
    REP(i, i0, N) {
      ll y = x | (1LL << i);
      if (L[x] > Y) L[y] = Y + 1;
      else {
        ll a = A[i] / gcd(L[x], A[i]);
        if (__builtin_mul_overflow(L[x], a, &L[y])) L[y] = Y + 1;
      }
    }
    G[x] = Y / L[x];
  }
  DLOGK(G);
  moebius_upper(G);
  ll ans = 0;
  REP(x, 0, 1LL << N) if (popcount((u64)x) == M) ans += G[x];
  cout << ans << "\n";

  return 0;
}

