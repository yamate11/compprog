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

// @@ !! LIM(digit debug)

// ---- inserted library file digit.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/digit.cc

struct digit_error : runtime_error {
  digit_error(const string& msg) : runtime_error(msg) {}
};

struct digit_util {
  const ll base;
  const vector<ll> _pow;

  static vector<ll> _make_pow(ll b) {
    vector<ll> ret;
    ll t = 1;
    while (true) {
      ret.push_back(t);
      if (__builtin_smulll_overflow(t, b, &t)) break;
    }
    return ret;
  };

  void range_error(string meth, ll param) const {
    throw digit_error(format("digit.{}: parameter {} out of range", meth, param));
  }

#if DEBUG
  ll zero_warning(string meth, bool quiet) const {
    if (not quiet) {
      cerr << format("You called {} with parameter 0.  It returns 0.  If this is OK, considter quiet=true.", meth)
           << endl;
    }
    return 0;
  }
#else
  ll zero_warning(string, bool) const { return 0; }
#endif

  digit_util(ll base_ = 10) : base(base_), _pow(_make_pow(base_)) {}
    
  ll pow_size() const { return _pow.size(); }
  ll pow(ll i) const {
    if (i < 0 or ssize(_pow) <= i) range_error("pow", i);
    return _pow[i];
  }

  ll width(ll x, bool quiet = false) const {
    if (x < 0) range_error("width", x);
    if (base == 2) return bit_width((unsigned long long)x);
    if (x == 0) return zero_warning("width", quiet);
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_min", i);
    if (i == 0) return zero_warning("nd_min", quiet);
    return pow(i - 1);
  }
  ll nd_max(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_max", i);
    if (i == 0) return zero_warning("nd_max", quiet);
    return nd_min(i + 1) - 1;
  }

  ll floor(ll x, bool quiet = false) const {
    if (x < 0) range_error("floor", x);
    if (x == 0) return zero_warning("floor", quiet);
    return pow(width(x) - 1);
  }
  ll ceil(ll x, bool quiet = false) const {
    if (x < 0) range_error("ceil", x);
    if (x == 0) return zero_warning("ceil", quiet);
    ll p = pow(width(x) - 1);
    return x == p ? p : pow(width(x));
  }

  ll log(ll x) const {
    if (x <= 0) range_error("log", x);
    return width(x) - 1;
  }

  ll d_at(ll x, ll i) const {
    if (x < 0) range_error("d_at", x);
    if (x == 0) return 0;
    if (i < 0) i += width(x);
    return (x / pow(i)) % base;
  }

  ll d_sub(ll x, ll pos, ll len) const {
    if (x < 0) range_error("d_sub", x);
    if (x == 0) return 0;
    ll w = width(x);
    if (pos < 0) pos += w;
    if (len < 0) { len = -len; pos = pos - len + 1; }
    if (pos < 0) { len += pos; pos = 0; }
    if (pos + len > w) len = w - pos;
    return (x % pow(pos + len)) / pow(pos);
  }

  template<bool big_endian>
  vector<ll> _gen_to_vector(ll x) const {
    if (x < 0) range_error("to_vector", x);
    if (x == 0) return vector<ll>{0};
    ll w = width(x);
    vector<ll> ret(w);
    for (int i = 0; i < w; i++) {
      if constexpr (big_endian) ret[w - 1 - i] = x % base;
      else                      ret[i]         = x % base;
      x /= base;
    }
    return ret;
  }
  vector<ll> to_vector(ll x) const { return _gen_to_vector<false>(x); }
  vector<ll> to_vector_big_endian(ll x) const { return _gen_to_vector<true>(x); }

  template<bool big_endian>
  ll _gen_from_vector(const auto& vec) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(vec); i++) {
      ll j;
      if constexpr (big_endian) j = ssize(vec) - 1 - i; else j = i;
      ret += vec[j] * pow(i);
    }
    return ret;
  }
  ll from_vector(const auto& vec) const { return _gen_from_vector<false>(vec); }
  ll from_vector_big_endian(const auto& vec) const { return _gen_from_vector<true>(vec); }

  string to_string(ll x, bool upcase = false) const {
    if (x < 0) range_error("to_string", x);
    if (x == 0) return string("0");
    char ten = upcase ? 'A' : 'a';
    ll w = width(x);
    string ret(w, ' ');
    for (ll i = w - 1; x != 0; x /= base, i--) {
      ll y = x % base;
      ret[i] = y < 10 ? '0' + y : ten + (y - 10);
    }
    return ret;
  }

  string to_string_padding(ll x, ll width, char c = '0', bool upcase = false) const {
    string s = to_string(x, upcase);
    if (ssize(s) >= width) return s;
    return string(width - ssize(s), c) + s;
  }

  static ll _get_digit_char(char c) {
    if ('0' <= c and c <= '9')      return c - '0';
    else if ('a' <= c and c <= 'z') return c - 'a' + 10;
    else if ('A' <= c and c <= 'Z') return c - 'A' + 10;
    else throw runtime_error("_get_digit_char: unknown letter");
  }

  ll from_string(string s) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(s); i++) ret += _get_digit_char(s[i]) * pow(ssize(s) - 1 - i);
    return ret;
  }


};

// ---- end digit.cc

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

  ll t; cin >> t;
  REP(tt, 0, t) {
    ll N; cin >> N;
    string s; cin >> s;
    ll i0 = 0; ll j0 = N - 1;
    for (; i0 <  N and s[i0] == '0'; i0++);
    for (; j0 >= 0 and s[j0] == '1'; j0--);
    j0++;
    vector<ll> cnt0(N + 1), cnt1(N + 1);
    REPrev(i, j0 - 1, i0) cnt0[i] = cnt0[i + 1] + (s[i] == '0' ? 1 : 0);
    REP(i, i0, j0) cnt1[i + 1] = cnt1[i] + (s[i] == '1' ? 1 : 0);
    DLOGK(i0, j0, cnt0, cnt1);
    auto check = [&]() -> bool {
      REP(i, i0, j0) {
        if (s[i] == '0' and cnt1[i] % 2 != 0) return false;
        if (s[i] == '1' and cnt0[i] % 2 != 0) return false;
      }
      return true;
    };
    cout << (check() ? "Bob" : "Alice") << "\n";
  }

  /*
  digit_util du2(2);


  ll N; cin >> N;

  auto mys = [&](ll x) -> string { return du2.to_string_padding(x, N); };

  set<string> ss;
  vector<int> tbl(1LL << N, -1);
  REP(x, 0, 1LL << N) {
    auto check = [&]() -> int {
      REP(y, 0, 1LL << N) {
        ll revn = 0;
        ll cnt1 = 0;
        REPrev(i, N - 1, 0) if (y >> i & 1) {
          if (x >> i & 1) cnt1++;
          else revn += cnt1;
        }
        if (revn % 2 == 1) {
          ll rem = 0;
          REPrev(i, N - 1, 0) {
            if (not (y >> i & 1)) rem = rem * 2 + (x >> i & 1);
          }
          assert(rem < x);
          if (tbl[rem] == 1) {
            DLOGKL("first", mys(x), mys(y), mys(rem), revn);
            return 0;
          }
        }
      }
      return 1;
    };
    tbl[x] = check();
    if (tbl[x] == 1) {
      string s = mys(x);
      ll i = 0;
      ll j = N - 1;
      for (; i < N and s[i] == '0'; i++);
      for (; j >= 0 and s[j] == '1'; j--);
      if (j + 1 - i > 0) ss.insert(s.substr(i, j + 1 - i));
      // cout << i << " " << j << " " << s << " " << s.substr(i, j + 1 - i) << "\n";
    }
  }
  for (string s : ss) { cout << s << endl; }
  */


  return 0;
}

