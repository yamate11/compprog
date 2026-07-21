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

// @@ !! LIM(smallVec perm debug forall segTree)

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

// ---- inserted library file smallVec.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/smallVec.cc

template<int bits>
struct small_vector_u64 {
  u64 impl;

  small_vector_u64(u64 impl_ = 0) : impl(impl_) {}
  small_vector_u64(const small_vector_u64& o) : impl(o.impl) {}
  small_vector_u64(initializer_list<int> init) : impl(0) {
    int i = 0;
    for (int x : init) set(i++, x);
  }
  small_vector_u64(const auto& v, int k) : impl(0) { for (int i = 0; i < k; i++) set(i, v[i]); }

  small_vector_u64& operator=(const small_vector_u64& o) { impl = o.impl; return *this; }

  constexpr u64 mask() const { return (1ULL << bits) - 1; }

  struct Subst {
    small_vector_u64& x;
    int i;
    Subst(small_vector_u64& x_, int i_) : x(x_), i(i_) {}
    Subst& operator=(ll t) { x.set(i, t); return *this; }
    Subst& operator=(const Subst& o) { return (*this) = ll(o); }
    operator ll() const { return x.at(i); }
  };

  ll set(ll i, ll t) {
    impl &= ~(mask() << (i * bits));
    impl |= t << (i * bits);
    return t;
  }

  ll at(ll i) const { return (impl >> (i * bits)) & mask(); }
  Subst rs(ll i) { return Subst(*this, i); }
  ll operator[](ll i) const { return at(i); }
  Subst operator[](ll i) { return rs(i); }

  bool operator==(const small_vector_u64& o) const { return impl == o.impl; }
  operator u64() const { return impl; }

  string show(int len=-1) const {
    string ret = "[";
    if (len < 0) len = 64 / bits;
    for (ll i = 0; i < len; i++) {
      if (i > 0) ret += ", ";
      ret += to_string(at(i));
    }
    ret += ']';
    return ret;
  }

  friend ostream& operator<<(ostream& os, const small_vector_u64& vec) { return os << vec.show(); }
};

template <int bits>
struct safe_custom_hash<small_vector_u64<bits>, void> {
  size_t operator()(const small_vector_u64<bits>& x) const {
    return safe_custom_hash<u64>{}(u64(x));
  }
};

struct small_vector_string {
  string impl;
  small_vector_string() : impl() {}
  small_vector_string(ll sz, ll init = 0) : impl(sz, (char)init) {}
  small_vector_string(const string& impl_) : impl(impl_) {}
  small_vector_string(string&& impl_) : impl(move(impl_)) {}
  small_vector_string(initializer_list<int> init) : impl() { for (int x : init) impl += (char)x; }
  small_vector_string(const auto& v, int k) : impl() { for (int i = 0; i < k; i++) impl += (char)(v[i]); }

  // We employ Subst struct so that "cerr << vec[0];" produces "0" rather than "^@".
  struct Subst {
    small_vector_string& x;
    int i;
    Subst(small_vector_string& x_, int i_) : x(x_), i(i_) {}
    Subst& operator=(ll t) { x.impl[i] = t; return *this; }
    Subst& operator=(const Subst& o) { return (*this) = ll(o); }
    operator ll() const { return ll(x.impl[i]); }
  };

  ll operator[](ll i) const { return impl[i]; }
  Subst operator[](ll i) { return Subst(*this, i); }

  bool operator==(const small_vector_string& o) const { return impl == o.impl; }
  operator string() const { return impl; }

  string show() const {
    string ret = "[";
    for (ll i = 0; i < ssize(impl); i++) {
      if (i > 0) ret += ", ";
      ret += to_string(impl[i]);
    }
    ret += ']';
    return ret;
  }

  friend ostream& operator<<(ostream& os, const small_vector_string& vec) { return os << vec.show(); }
};

template <>
struct safe_custom_hash<small_vector_string, void> {
  size_t operator()(const small_vector_string& x) const {
    return safe_custom_hash<string>{}(string(x));
  }
};

// ---- end smallVec.cc

// ---- inserted library file perm.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/perm.cc

template <bool dup, typename T>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;
  vector<T> mapping;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {
    if (n >= 0) {
      mapping = vector<T>(n);
      for (int i = 0; i < n; i++) {
        if constexpr (is_integral<T>::value) mapping[i] = (T)i;
        else mapping[i] = T();
      }
    }
  }
  IntPermBase(int n_, int r_, vector<T> mp) : n(n_), r(r_), started(false), mapping(move(mp)) {
    if (ssize(mapping) != n) throw runtime_error("IntPermBase: incorrect mapping length");
  }

  T at(int i) const { return mapping[vec[i]]; }

  T operator[](int i) const { return at(i); }

  void set_mapping(auto f) {
    for (int i = 0; i < n; i++) mapping[i] = f(i);
  }

  vector<T> vec_view() const {
    vector<T> res;
    for (int i = 0; i < r; i++) res.push_back(mapping[vec[i]]);
    return res;
  }
};

template<typename T = int>
struct IntPerm : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started;

  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (int i = 0; i < r; i++) {
      for (int j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false, T>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntPerm(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (int j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (int k = 0; k < (int)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

template<typename T = int>
struct IntComb : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntComb(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

template<typename T = int>
struct IntDupPerm : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupPerm(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupPerm(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

template<typename T = int>
struct IntDupComb : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupComb(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupComb(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

struct IDCBoxBall {
  int box;
  int ball;
  IntDupComb<> idc;
  vector<int> numBalls;
  IDCBoxBall(int box_, int ball_) : box(box_), ball(ball_), idc(box, ball) {}
  bool get() {
    bool b = idc.get();
    if (not b) return false;
    numBalls = vector<int>(box);
    for (int i = 0; i < ball; i++) numBalls[idc.at(i)]++;
    return true;
  }
  int at(int i) const { return numBalls[i]; }
  int operator[](int i) const { return at(i); }
  vector<int> vec_view() const { return numBalls; }
};


template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }
  int operator[](int i) const { return at(i); }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (int i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }
};

template<typename INT>
struct IntPartition {
  INT n;
  vector<INT> vec;
  bool started = false;
  IntPartition(INT n_) : n(n_) {}
  
  bool get() {
    if (not started) {
      started = true;
      vec = vector<INT>(n, 1);
      return true;
    }else if (ssize(vec) == 1) {
      started = false;
      return false;
    }else {
      ll b = vec.back(); vec.pop_back();
      ll a = vec.back(); vec.pop_back();
      ll c = a + b;
      ll a1 = a + 1;
      while (c - a1 >= a1) {
        vec.push_back(a1);
        c -= a1;
      }
      vec.push_back(c);
      return true;
    }
  }

  INT at(int i) const { return vec[i]; }
  const vector<INT>& vec_view() const { return vec; }
};

// ---- end perm.cc

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

// ---- inserted library file forall.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// ---- inserted library file segTree.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/segTree.cc
// https://github.com/yamate11/compprog-clib/blob/master/segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

pair<int, int> segtree_range_of_node(int ht, unsigned i) {
  unsigned m = bit_floor(i);
  unsigned w = ht + 1 - bit_width(i);
  int lo = (i ^ m) << w;
  int hi = lo + (1LL << w);
  return make_pair(lo, hi);
}

vector<int> segtree_nodes_for_range(int ht, unsigned lo, unsigned hi) {
  vector<int> left;
  vector<int> right;
  lo = (1 << ht) + lo;
  hi = (1 << ht) + hi - 1;
  while (lo <= hi) {
    if (lo == hi) {
      left.push_back(lo);
      break;
    }
    if (lo & 1) {
      left.push_back(lo);
      lo++;
    }
    if (not (hi & 1)) {
      right.push_back(hi);
      hi--;
    }
    lo >>= 1;
    hi >>= 1;
  }
  while (not right.empty()) {
    left.push_back(right.back());
    right.pop_back();
  }
  return left;
}

template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy> 
struct GenSegTree {
  using GST = GenSegTree<DAT, OP, ADD_t, COMP_t, APPL_t, lazy>;

  int orig_size;     // size of initdat
  int size;	     // power of two; >= 2
  int height;        // size = 1 << height;
  vector<DAT> node;  // vector of size 2*size.
                     // 0                 : unused
                     // 1    ... size-1   : interval
                     // size ... 2*size-1 : leaf
  vector<OP> susp;   // vector of size size.
                     // suspended operation FOR CHILDREN
                     // (already applied to this node)
  DAT unit_dat;
  OP unit_op;
  ADD_t add;
  COMP_t comp;
  APPL_t appl;
    
  GenSegTree() {}

  GenSegTree(DAT unit_dat_, OP unit_op_, ADD_t add_, COMP_t comp_, APPL_t appl_,
             const vector<DAT>& initdat = vector<DAT>())
    : unit_dat(unit_dat_), unit_op(unit_op_),
      add(add_), comp(comp_), appl(appl_) { set_data(initdat); }

  void set_data(const vector<DAT>& initdat) {
    orig_size = initdat.size();
    if (initdat.size() <= 1) height = 0;
    else   height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) node[size + i] = initdat[i];
    for (int t = size - 1; t >= 1; t--) node[t] = add(node[t<<1|0], node[t<<1|1]);
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int t) {
    node[t] = appl(susp[t], add(node[t<<1|0], node[t<<1|1]));
  }

  void child_updated(int l, int r) {
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      child_updated_sub(l);
      if (l < r) child_updated_sub(r);
    }
  }

  void node_op(int i, OP f) {
    node[i] = appl(f, node[i]);
    if (i < size) susp[i] = comp(f, susp[i]);
  }

  // Note that susp[i] HAS ALREADY BEEN APPLIED TO node[i].
  // When push_one(i) is called, susp[j] is updated (for j : i's child) and it is applied to node[j].
  void push_one(int i) {
    node_op(i<<1|0, susp[i]);
    node_op(i<<1|1, susp[i]);
    susp[i] = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      push_one(lz);
      if (lz < rz) push_one(rz);
    }
  }

  DAT query(int l, int r) {
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    l += size;
    r += size;
    if constexpr(lazy) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node[l]);
	l++;
      }
      if (r & 1) {
	ret_r = add(node[r-1], ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    return ret;
  }

  const DAT& at(int i) {
    if constexpr(lazy) push_upto(size + i, size + i + 1);
    return node[size + i];
  }

  const DAT& set_single(int i, const DAT& t) {
    ll x = size + i;
    if constexpr(lazy) push_upto(x, x + 1);
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
    return t;
  }

  struct STSubst {
    GenSegTree& st;
    int i;
    STSubst(GenSegTree& st_, int i_) : st(st_), i(i_) {}
    const DAT& operator=(const DAT& t) { return st.set_single(i, t); }
  };

  // Reference for Substitution
  STSubst rs(int i) { return STSubst(*this, i); }

  // obsolete
  template<bool xx = lazy> enable_if_t<! xx> update(int i, DAT t) {
    ll x = size + i;
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  template<bool xx = lazy> enable_if_t<xx> update(int l, int r, const OP& f) {
    if (l >= r) return;
    l += size;
    r += size;
    push_upto(l, r);
    int l0 = l, r0 = r;
    while (l < r) {
      if (l & 1) {
	node_op(l, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, f);
      }
      l >>= 1;
      r >>= 1;
    }
    child_updated(l0, r0);
  }

  pair<int, int> range_of_node(unsigned i) { return segtree_range_of_node(height, i); }

  vector<int> nodes_for_range(unsigned lo, unsigned hi) { return segtree_nodes_for_range(height, lo, hi); }

  friend ostream& operator<<(ostream& os, GenSegTree& st) {
    os << '[';
    for (int i = 0; i < st.orig_size; i++) {
      if (i > 0) os << ", ";
      os << st.at(i);
    }
    os << ']';
    return os;
  }

  int binsearch_r_until(const auto& check, int l) {
    // DLOGKL("in: binsearch_r_until", l);
    if (not check(unit_dat)) return l - 1;
    if (l == orig_size) return l;
    DAT val = unit_dat;
    int x = l + size;
    if constexpr(lazy) push_upto(x, x + 1);
    while (true) {
      if (x & 1) {
        DAT t = add(val, node[x]);
        if (not check(t)) break;
        val = t;
        x++;
        if (__builtin_popcountll(x) == 1) return orig_size;
      }
      x >>= 1;
      // DLOGKL("1: ", x, val);
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x <<= 1;
      DAT t = add(val, node[x]);
      if (check(t)) {
        x++;
        val = t;
      }
      // DLOGKL("2: ", x, val);
    }
    // DLOGKL("3: ", x - size, orig_size);
    return min(x - size, orig_size);
  }

  int binsearch_r_from(const auto& check, int l) {
    return binsearch_r_until([&](DAT x) { return not check(x); }, l) + 1;
  }

  int binsearch_l_until(const auto& check, int r) {
    if (not check(unit_dat)) return r + 1;
    if (r == 0) return 0;
    DAT val = unit_dat;
    int x = r + size;
    if (x == 2 * size) {
      if (check(node[1])) return 0;
      x = 1;
    }else {
      if constexpr(lazy) push_upto(x - 1, x);
      while (true) {
        if (x & 1) {
          x--;
          DAT t = add(node[x], val);
          if (not check(t)) break;
          val = t;
          if (__builtin_popcountll(x) == 1) return 0;
        }
        x >>= 1;
      }
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x = x << 1 | 1;
      DAT t = add(node[x], val);
      if (check(t)) {
        val = t;
        x--;
      }
    }
    return x + 1 - size;
  }

  int binsearch_l_from(const auto& check, int r) {
    return binsearch_l_until([&](DAT x) { return not check(x); }, r) - 1;
  }

  vector<DAT> vec_view() {
    vector<DAT> ret(orig_size);
    for (int i = 0; i <  orig_size; i++) ret[i] = at(i);
    return ret;
  };

};

template<typename DAT, typename OP>
auto make_seg_tree_lazy(DAT unit_dat, OP unit_op, auto add, auto comp, auto appl,
                        const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true>;
  return ret_t(unit_dat, unit_op, add, comp, appl, initdat);
}

void* dummy_comp(void*, void*) { return nullptr; }
template<typename DAT>
DAT dummy_appl(void*, const DAT& y) { return y; }

template<typename DAT>
auto make_seg_tree(DAT unit_dat, auto add, const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, void*, decltype(add), void* (*)(void*, void*), DAT (*)(void*, const DAT&), false>;
  return ret_t(unit_dat, nullptr, add, dummy_comp, dummy_appl<DAT>, initdat);
}

// ---- end segTree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using svec = small_vector_u64<4>;

  // @DefStruct(sta, (val, (nxt, svec))) [Z5qo65dI]
  struct sta {
    ll val;
    svec nxt;
    string show() const {
      return "(" + to_string(val) + ", " + g_show(nxt) + ")";
    }
    bool operator==(const sta&) const = default;
  };
  // @End [Z5qo65dI]

  // safe_umap<svec, sta> mp;

  ll N = 10;
  REP(n, 1, N + 1) {
    string fname = "o" + to_string(n) + ".txt";
    ifstream infile(fname);
    while (true) {
      ll x, d;
      if (not (infile >> x >> d)) break;
      // cout << (svec)x << " " << d << endl;
    }
  }

  return 0;
}

