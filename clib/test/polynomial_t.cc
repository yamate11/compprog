#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< mod debug f:perfmeas polynomial)

// ---- inserted function f:<< from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file algOp.cc
#line 105 "/home/y-tanabe/proj/compprog/clib/algOp.cc"

// Common definitions
//    zero, one, inverse

template<typename T>
constexpr T zero(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)0; }
  else { return t.zero(); }
}

template<typename T>
constexpr T one(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)1; }
  else { return t.one(); }
}

template<typename T>
constexpr T inverse(const T& t) {
  if constexpr (is_floating_point_v<T>) { return 1.0 / t; }
  else { return t.inverse(); }
}

// begin -- detection ideom
//    cf. https://blog.tartanllama.xyz/detection-idiom/

namespace detail {
  template <template <class...> class Trait, class Enabler, class... Args>
  struct is_detected : false_type{};

  template <template <class...> class Trait, class... Args>
  struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : true_type{};
}

template <template <class...> class Trait, class... Args>
using is_detected = typename detail::is_detected<Trait, void, Args...>::type;

// end -- detection ideom


template<typename T>
// using subst_add_t = decltype(T::subst_add(declval<typename T::value_type &>(), declval<typename T::value_type>()));
using subst_add_t = decltype(T::subst_add);
template<typename T>
using has_subst_add = is_detected<subst_add_t, T>;

template<typename T>
using add_t = decltype(T::add);
template<typename T>
using has_add = is_detected<add_t, T>;

template<typename T>
using subst_mult_t = decltype(T::subst_mult);
template<typename T>
using has_subst_mult = is_detected<subst_mult_t, T>;

template<typename T>
using mult_t = decltype(T::mult);
template<typename T>
using has_mult = is_detected<mult_t, T>;

template<typename T>
using subst_subt_t = decltype(T::subst_subt);
template<typename T>
using has_subst_subt = is_detected<subst_subt_t, T>;

template<typename T>
using subt_t = decltype(T::subt);
template<typename T>
using has_subt = is_detected<subt_t, T>;

template <typename Opdef>
struct MyAlg {
  using T = typename Opdef::value_type;
  using value_type = T;
  T v;
  MyAlg() {}
  MyAlg(const T& v_) : v(v_) {}
  MyAlg(T&& v_) : v(move(v_)) {}
  bool operator==(MyAlg o) const { return v == o.v; }
  bool operator!=(MyAlg o) const { return v != o.v; }
  operator T() const { return v; }
  MyAlg zero() const { return MyAlg(Opdef::zero(v)); }
  MyAlg one() const { return MyAlg(Opdef::one(v)); }
  MyAlg inverse() const { return MyAlg(Opdef::inverse(v)); }
  MyAlg operator/=(const MyAlg& o) { return *this *= o.inverse(); }
  MyAlg operator/(const MyAlg& o) const { return (*this) * o.inverse(); }
  MyAlg operator-() const { return zero() - *this; }

  MyAlg& operator +=(const MyAlg& o) { 
    if constexpr (has_subst_add<Opdef>::value) {
      Opdef::subst_add(v, o.v);
      return *this;
    }else if constexpr (has_add<Opdef>::value) {
      v = Opdef::add(v, o.v);
      return *this;
    }else static_assert("either subst_add or add is needed.");

  }
  MyAlg operator +(const MyAlg& o) const { 
    if constexpr (has_add<Opdef>::value) {
      return MyAlg(Opdef::add(v, o.v));
    }else if constexpr (has_subst_add<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_add(ret.v, o.v);
      return ret;
    }else static_assert("either subst_add or add is needed.");
  }
  MyAlg& operator *=(const MyAlg& o) { 
    if constexpr (has_subst_mult<Opdef>::value) {
      Opdef::subst_mult(v, o.v);
      return *this;
    }else if constexpr (has_mult<Opdef>::value) {
      v = Opdef::mult(v, o.v);
      return *this;
    }else static_assert("either subst_mult or mult is needed.");

  }
  MyAlg operator *(const MyAlg& o) const { 
    if constexpr (has_mult<Opdef>::value) {
      return MyAlg(Opdef::mult(v, o.v));
    }else if constexpr (has_subst_mult<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_mult(ret.v, o.v);
      return ret;
    }else static_assert("either subst_mult or mult is needed.");
  }
  MyAlg& operator -=(const MyAlg& o) { 
    if constexpr (has_subst_subt<Opdef>::value) {
      Opdef::subst_subt(v, o.v);
      return *this;
    }else if constexpr (has_subt<Opdef>::value) {
      v = Opdef::subt(v, o.v);
      return *this;
    }else static_assert("either subst_subt or subt is needed.");

  }
  MyAlg operator -(const MyAlg& o) const { 
    if constexpr (has_subt<Opdef>::value) {
      return MyAlg(Opdef::subt(v, o.v));
    }else if constexpr (has_subst_subt<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_subt(ret.v, o.v);
      return ret;
    }else static_assert("either subst_subt or subt is needed.");
  }
  friend istream& operator >>(istream& is, MyAlg& t)       { is >> t.v; return is; }
  friend ostream& operator <<(ostream& os, const MyAlg& t) { os << t.v; return os; }
};





// ---- end algOp.cc

// ---- inserted function f:gcd from util.cc

// auto [g, s, t] = eGCD(a, b)
//     g == gcd(|a|, |b|) and as + bt == g           
//     |a| and |b| must be less than 2^31.
tuple<ll, ll, ll> eGCD(ll a, ll b) {
#if DEBUG
  if (abs(a) >= (1LL << 31) or abs(b) >= (1LL << 31)) throw runtime_error("eGCD: not within the range");
#endif    
  array<ll, 50> vec;  // Sufficiently large for a, b < 2^31.
  ll idx = 0;
  while (a != 0) {
    ll x = b / a;
    ll y = b % a;
    vec[idx++] = x;
    b = a;
    a = y;
  }
  ll g, s, t;
  if (b < 0) { g = -b; s = 0; t = -1; }
  else       { g =  b; s = 0; t =  1; }
  while (idx > 0) {
    ll x = vec[--idx];
    ll old_t = t;
    t = s;
    s = old_t - x * s;
  }
  return {g, s, t};
}

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = eGCD(x1, -x2);
  ll gq = (a2 - a1) / g;
  ll gr = (a2 - a1) % g;
  if (gr != 0) return {-1, -1};
  s *= gq;
  t *= gq;
  ll z = x1 / g * x2;
  // DLOGK(z);
  s = s % (x2 / g);
  ll r = (x1 * s + a1) % z;
  // DLOGK(r);
  if (r < 0) r += z;
  // DLOGK(r);
  return {r, z};
};

// Chinese Remainder Theorem
//
//    r = crt(a1, x1, a2, x2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  0 <= r < lcm(x1, x2)
//    If no such r exists, returns -1
//    Note: x1 and x2 should >= 1.  a1 and a2 can be negative or zero.
//
//    r = crt(as, xs)
//    ==>   for all i. r = as[i] (mod xs[i]); 0 <= r < lcm(xs)
//    If no such r exists, returns -1
//    Note: xs[i] should >= 1.  as[i] can be negative or zero.
//          It should hold: len(xs) == len(as) > 0

ll crt(ll a1, ll x1, ll a2, ll x2) { return crt_sub(a1, x1, a2, x2).first; }

ll crt(vector<ll> as, vector<ll> xs) {
  // DLOGKL("crt", as, xs);
  assert(xs.size() == as.size() && xs.size() > 0);
  ll r = as[0];
  ll z = xs[0];
  for (size_t i = 1; i < xs.size(); i++) {
    // DLOGK(i, r, z, as[i], xs[i]);
    tie(r, z) = crt_sub(r, z, as[i], xs[i]);
    // DLOGK(r, z);
    if (r == -1) return -1;
  }
  return r;
}

// ---- end f:gcd

// ---- inserted library file mod.cc
#line 38 "/home/y-tanabe/proj/compprog/clib/mod.cc"

template<int mod=0>
struct FpG {   // G for General
  static ll dyn_mod;

  static ll getMod() {
    if (mod == 0) return dyn_mod;
    else          return mod;
  }

  static void setMod(ll _mod) {  // effective only when mod == 0
    dyn_mod = _mod;
  }

  static ll _conv(ll x) {
    if (x >= getMod())  return x % getMod();
    if (x >= 0)         return x;
    if (x >= -getMod()) return x + getMod();
    ll y = x % getMod();
    if (y == 0) return 0;
    return y + getMod();
  }

  ll val;

  FpG(int t = 0) : val(_conv(t)) {}
  FpG(ll t) : val(_conv(t)) {}
  FpG(const FpG& t) : val(t.val) {}
  FpG& operator =(const FpG& t) { val = t.val; return *this; }
  FpG& operator =(ll t) { val = _conv(t); return *this; }
  FpG& operator =(int t) { val = _conv(t); return *this; }

  FpG& operator +=(const FpG& t) {
    val += t.val;
    if (val >= getMod()) val -= getMod();
    return *this;
  }

  FpG& operator -=(const FpG& t) {
    val -= t.val;
    if (val < 0) val += getMod();
    return *this;
  }

  FpG& operator *=(const FpG& t) {
    val = (val * t.val) % getMod();
    return *this;
  }

  FpG inv() const {
    if (val == 0) { throw runtime_error("FpG::inv(): called for zero."); }
    auto [g, u, v] = eGCD(val, getMod());
    if (g != 1) { throw runtime_error("FpG::inv(): not co-prime."); }
    return FpG(u);
  }

  FpG zero() const { return (FpG)0; }
  FpG one() const { return (FpG)1; }
  FpG inverse() const { return inv(); }

  FpG& operator /=(const FpG& t) {
    return (*this) *= t.inv();
  }

  FpG operator +(const FpG& t) const { return FpG(val) += t; }
  FpG operator -(const FpG& t) const { return FpG(val) -= t; }
  FpG operator *(const FpG& t) const { return FpG(val) *= t; }
  FpG operator /(const FpG& t) const { return FpG(val) /= t; }
  FpG operator -() const { return FpG(-val); }

  bool operator ==(const FpG& t) const { return val == t.val; }
  bool operator !=(const FpG& t) const { return val != t.val; }
  
  operator ll() const { return val; }

  friend FpG operator +(int x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(int x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(int x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(int x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(int x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(int x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(ll x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(ll x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(ll x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(ll x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(ll x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(ll x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, int y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, int y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, int y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, int y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, int y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, int y) { return x != FpG(y); }
  friend FpG operator +(const FpG& x, ll y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, ll y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, ll y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, ll y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, ll y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, ll y) { return x != FpG(y); }

  friend istream& operator>> (istream& is, FpG& t) {
    ll x; is >> x;
    t = x;
    return is;
  }

  friend ostream& operator<< (ostream& os, const FpG& t) {
    os << t.val;
    return os;
  }

};
template<int mod>
ll FpG<mod>::dyn_mod;

template<typename T>
class Comb {
  int nMax;
  vector<T> vFact;
  vector<T> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact[0] = 1;
    for (int i = 1; i <= nMax; i++) vFact[i] = i * vFact[i-1];
    vInvFact.at(nMax) = (T)1 / vFact[nMax];
    for (int i = nMax; i >= 1; i--) vInvFact[i-1] = i * vInvFact[i];
  }
  T fact(int n) { return vFact[n]; }
  T binom(int n, int r) {
    if (r < 0 || r > n) return (T)0;
    return vFact[n] * vInvFact[r] * vInvFact[n-r];
  }
  T binom_dup(int n, int r) { return binom(n + r - 1, r); }
  // The number of permutation extracting r from n.
  T perm(int n, int r) {
    return vFact[n] * vInvFact[n-r];
  }
};

constexpr int primeA = 1'000'000'007;
constexpr int primeB = 998'244'353;          // '
using FpA = FpG<primeA>;
using FpB = FpG<primeB>;

// ---- end mod.cc

// ---- inserted library file debug.cc
#line 42 "/home/y-tanabe/proj/compprog/clib/debug.cc"
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// ---- inserted library file power.cc
#line 16 "/home/y-tanabe/proj/compprog/clib/power.cc"

template<typename T>
T power(const T& a, ll b) {
  auto two_pow = a;
  auto ret = one<T>(a);
  while (b > 0) {
    if (b & 1LL) ret *= two_pow;
    two_pow *= two_pow;
    b >>= 1;
  }
  return ret;
}

// ---- end power.cc

// ---- inserted library file convolution.cc
#line 24 "/home/y-tanabe/proj/compprog/clib/convolution.cc"

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ac_ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

// @param m `1 <= m`
// @return x mod m
constexpr long long ac_safe_mod(long long x, long long m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr pair<long long, long long> ac_inv_gcd(long long a, long long b) {
  a = ac_safe_mod(a, b);
  if (a == 0) return {b, 0};

  // Contracts:
  // [1] s - m0 * a = 0 (mod b)
  // [2] t - m1 * a = 0 (mod b)
  // [3] s * |m1| + t * |m0| <= b
  long long s = b, t = a;
  long long m0 = 0, m1 = 1;

  while (t) {
    long long u = s / t;
    s -= t * u;
    m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

    // [3]:
    // (s - t * u) * |m1| + t * |m0 - m1 * u|
    // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
    // = s * |m1| + t * |m0| <= b

    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  // by [3]: |m0| <= b/g
  // by g != b: |m0| < b/g
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = ac_safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int ac_primitive_root_constexpr(int m) {
  if (m == 2) return 1;
  if (m == 167772161) return 3;
  if (m == 469762049) return 3;
  if (m == 754974721) return 11;
  if (m == 998244353) return 3;
  int divs[20] = {};
  divs[0] = 2;
  int cnt = 1;
  int x = (m - 1) / 2;
  while (x % 2 == 0) x /= 2;
  for (int i = 3; (long long)(i)*i <= x; i += 2) {
    if (x % i == 0) {
      divs[cnt++] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    divs[cnt++] = x;
  }
  for (int g = 2;; g++) {
    bool ok = true;
    for (int i = 0; i < cnt; i++) {
      if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return g;
  }
}

template<int mod>
int prim_root = mod > 0 ? ac_primitive_root_constexpr(mod) : 0;

template<int mod>
int cv_get_mod() {
  if (mod > 0) return mod;
  else return FpG<mod>::getMod();
}

template<int mod>
int cv_get_primitive_root() {
  if (mod > 0) return prim_root<mod>;
  else return ac_primitive_root_constexpr(FpG<mod>::getMod());
}


template<int mod>
void butterfly(vector<FpG<mod>>& a) {
  using Fp = FpG<mod>;
  int g = cv_get_primitive_root<mod>();
  int n = int(a.size());
  int h = ac_ceil_pow2(n);

  DLOGK_LIB(g);

  static bool first = true;
  static Fp sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
  if (first) {
    if (mod > 0) {
      first = false;
    }
    Fp es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    int cnt2 = __builtin_ctz(cv_get_mod<mod>() - 1);
    Fp e = power<Fp>(Fp(g), (cv_get_mod<mod>() - 1) >> cnt2), ie = e.inv();
    for (int i = cnt2; i >= 2; i--) {
      // e^(2^i) == 1
      es[i - 2] = e;
      ies[i - 2] = ie;
      e *= e;
      ie *= ie;
    }
    Fp now = 1;
    for (int i = 0; i < cnt2 - 2; i++) {
      sum_e[i] = es[i] * now;
      now *= ies[i];
    }
    DLOGK_LIB(now);
  }
  DLOGK_LIB(cv_get_mod<mod>());
  for (int ph = 1; ph <= h; ph++) {
    int w = 1 << (ph - 1), p = 1 << (h - ph);
    Fp now = 1;
    for (int s = 0; s < w; s++) {
      int offset = s << (h - ph + 1);
      for (int i = 0; i < p; i++) {
        auto l = a[i + offset];
        auto r = a[i + offset + p] * now;
        a[i + offset] = l + r;
        a[i + offset + p] = l - r;
      }
      now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
    }
  }
}

template<int mod>
void butterfly_inv(vector<FpG<mod>>& a) {
  using Fp = FpG<mod>;
  int g = cv_get_primitive_root<mod>();
  int n = int(a.size());
  int h = ac_ceil_pow2(n);

  static bool first = true;
  static Fp sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
  if (first) {
    if (mod > 0) {
      first = false;
    }
    Fp es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    int cnt2 = __builtin_ctz(cv_get_mod<mod>() - 1);
    Fp e = power<Fp>(Fp(g), (cv_get_mod<mod>() - 1) >> cnt2), ie = e.inv();
    for (int i = cnt2; i >= 2; i--) {
      // e^(2^i) == 1
      es[i - 2] = e;
      ies[i - 2] = ie;
      e *= e;
      ie *= ie;
    }
    Fp now = 1;
    for (int i = 0; i < cnt2 - 2; i++) {
      sum_ie[i] = ies[i] * now;
      now *= es[i];
    }
  }

  for (int ph = h; ph >= 1; ph--) {
    int w = 1 << (ph - 1), p = 1 << (h - ph);
    Fp inow = 1;
    for (int s = 0; s < w; s++) {
      int offset = s << (h - ph + 1);
      for (int i = 0; i < p; i++) {
        auto l = a[i + offset];
        auto r = a[i + offset + p];
        a[i + offset] = l + r;
        a[i + offset + p] =
          (long long)(cv_get_mod<mod>() + l.val - r.val) * inow.val;
      }
      inow *= sum_ie[__builtin_ctz(~(unsigned int)(s))];
    }
  }
}

#if DEBUG
const ll lim_naive = 1;
#else
const ll lim_naive = 60;
#endif

template<int mod>
vector<FpG<mod>> convolution(vector<FpG<mod>> a, vector<FpG<mod>> b) {
  using Fp = FpG<mod>;
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  if (min(n, m) <= lim_naive) {
    if (n < m) {
      swap(n, m);
      swap(a, b);
    }
    vector<Fp> ans(n + m - 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i + j] += a[i] * b[j];
      }
    }
    return ans;
  }
  int z = 1 << ac_ceil_pow2(n + m - 1);
  a.resize(z);
  butterfly(a);
  b.resize(z);
  butterfly(b);
  DLOGK_LIB(a);
  DLOGK_LIB(b);
  for (int i = 0; i < z; i++) {
    a[i] *= b[i];
  }
  butterfly_inv(a);
  a.resize(n + m - 1);
  Fp iz = Fp(z).inv();
  for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
  return a;
}

template<int mod, class T> // T must be integral.
vector<T> sub_convolution(const vector<T>& a, const vector<T>& b) {

  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  using Fp = FpG<mod>;
  vector<Fp> a2(n), b2(m);
  for (int i = 0; i < n; i++) { a2[i] = Fp(a[i]); }
  for (int i = 0; i < m; i++) { b2[i] = Fp(b[i]); }
  DLOGK_LIB(a2);
  DLOGK_LIB(b2);
  auto c2 = convolution(move(a2), move(b2));
  DLOGK_LIB(c2);
  vector<T> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) { c[i] = c2[i].val; }
  return c;

}

vector<long long> convolution_ll(const vector<long long>& a,
                                 const vector<long long>& b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};

  static constexpr unsigned long long MOD1 = 754974721;  // 2^24
  static constexpr unsigned long long MOD2 = 167772161;  // 2^25
  static constexpr unsigned long long MOD3 = 469762049;  // 2^26
  static constexpr unsigned long long M2M3 = MOD2 * MOD3;
  static constexpr unsigned long long M1M3 = MOD1 * MOD3;
  static constexpr unsigned long long M1M2 = MOD1 * MOD2;
  static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

  static constexpr unsigned long long i1 =
    ac_inv_gcd(MOD2 * MOD3, MOD1).second;
  static constexpr unsigned long long i2 =
    ac_inv_gcd(MOD1 * MOD3, MOD2).second;
  static constexpr unsigned long long i3 =
    ac_inv_gcd(MOD1 * MOD2, MOD3).second;

  auto c1 = sub_convolution<MOD1>(a, b);
  auto c2 = sub_convolution<MOD2>(a, b);
  auto c3 = sub_convolution<MOD3>(a, b);
  DLOGKL_LIB("***", a);
  DLOGK_LIB(b);
  DLOGK_LIB(c1);
  DLOGK_LIB(c2);
  DLOGK_LIB(c3);

  vector<long long> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    unsigned long long x = 0;
    x += (c1[i] * i1) % MOD1 * M2M3;
    x += (c2[i] * i2) % MOD2 * M1M3;
    x += (c3[i] * i3) % MOD3 * M1M2;
    // B = 2^63, -B <= x, r(real value) < B
    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)
    // r = c1[i] (mod MOD1)
    // focus on MOD1
    // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)
    // r = x,
    //     x - M' + (0 or 2B),
    //     x - 2M' + (0, 2B or 4B),
    //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)
    // (r - x) = 0, (0)
    //           - M' + (0 or 2B), (1)
    //           -2M' + (0 or 2B or 4B), (2)
    //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)
    // we checked that
    //   ((1) mod MOD1) mod 5 = 2
    //   ((2) mod MOD1) mod 5 = 3
    //   ((3) mod MOD1) mod 5 = 4
    long long diff =
      c1[i] - ac_safe_mod((long long)(x), (long long)(MOD1));
    if (diff < 0) diff += MOD1;
    static constexpr unsigned long long offset[5] = {
      0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
    x -= offset[diff % 5];
    c[i] = x;
  }

  return c;
}

// ---- end convolution.cc

// ---- inserted library file polynomial.cc
#line 94 "/home/y-tanabe/proj/compprog/clib/polynomial.cc"

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

template<typename T> struct SparsePoly;

template<typename T>
vector<T> polyConvolution(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<int mod=0>
vector<FpG<mod>> polyConvolution(const vector<FpG<mod>>& a,
                                 const vector<FpG<mod>>& b) {
  vector<FpG<mod>> aa(a);
  vector<FpG<mod>> bb(b);
  return convolution(move(aa), move(bb));
}

template<typename T>
vector<T> polyConvolution_ll(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<>
vector<ll> polyConvolution_ll(const vector<ll>& a, const vector<ll>& b) {
  return convolution_ll(a, b);
}

// value of use_fft
//    0 ... multiplication is naive
//    1 ... multiplication uses convolution
//             in this case, T must be Fp with 2^c | Fp::MOD - 1
//    2 ... multiplication uses convolution_ll
//             in this case, T must be ll
template<typename T, int use_fft>
struct Polynomial {
  using value_type = T;
  using SP = SparsePoly<T>;

private:
  // The highest coefficient should not be zero.
  // Thus, the zero polynomial should be represented by the empty vector.
  vector<T> coef;

public:
  const vector<T>& coefVec() const { return coef; }
  T getCoef(ll n) const {
    if (n > degree()) return (T)0;
    return coef[n];
  }

  // Degree of the zero polynomial is -1.
  int degree() const { return coef.size() - 1; }

  void normalize() {
    while (!coef.empty() && coef.back() == (T)0) coef.pop_back();
  }

  Polynomial() : coef() {}
  Polynomial(T t) : coef() { if (t != (T)0) { coef.push_back(t); } }

  Polynomial(const vector<T>& coef_) : coef(coef_) { normalize(); }
  Polynomial(vector<T>&& coef_) : coef(move(coef_)) { normalize(); }

  Polynomial(const Polynomial& o) : coef(o.coef) {}
  Polynomial(Polynomial&& o) : coef(move(o.coef)) {}
  Polynomial& operator =(const Polynomial& o) {
    coef = o.coef;
    return *this;
  }
  Polynomial& operator =(Polynomial&& o) {
    coef = move(o.coef);
    return *this;
  }
  Polynomial& operator =(T t) {
    coef.resize(0);
    if (t != (T)0) { coef.push_back(t); }
    return *this;
  }

  void _from_sparse(const SP& sp) {
    coef = vector<T>(sp.degree() + 1);
    for (auto [i, t] : sp.coef) coef[i] = t;
  }
  Polynomial(const SP& sp) { _from_sparse(sp); }
  Polynomial& operator =(const SP& sp) {
    _from_sparse(sp);
    return *this;
  }

  Polynomial& operator +=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] += o.coef[i]; }
    normalize();
    return *this;
  }

  Polynomial& operator -=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] -= o.coef[i]; }
    normalize();
    return *this;
  }

  vector<T> coef_conv(const vector<T>& a, const vector<T>& b) const {
    if (use_fft == 0) {
      int a_size = a.size();
      int b_size = b.size();
      int new_size = a_size + b_size - 1;
      auto ret = vector<T>(new_size);
      for (int i = 0; i < new_size; i++) {
        for (int j = max(0, i - b_size + 1); j <= min(i, a_size - 1); j++) {
          ret[i] += a[j] * b[i - j];
        }
      }
      return ret;
    }else if (use_fft == 1) {
      return polyConvolution(a, b);
    }else if (use_fft == 2) {
      return polyConvolution_ll(a, b);
    }else {
      assert(0);
    }
  }

  constexpr Polynomial& operator *=(const Polynomial& o) {
    coef = coef_conv(coef, o.coef);
    normalize();
    return *this;
  }
  
  Polynomial operator -() const {
    return Polynomial() -= *this;
  }
  Polynomial operator +(const Polynomial& o) const {
    return Polynomial(*this) += o;
  }
  Polynomial operator -(const Polynomial& o) const {
    return Polynomial(*this) -= o;
  }
  Polynomial operator *(const Polynomial& o) const {
    return Polynomial(*this) *= o;
  }

  bool operator ==(const Polynomial& o) const { return coef == o.coef; }
  bool operator !=(const Polynomial& o) const { return coef != o.coef; }

  T atval(T t) const {
    T ret = 0;
    for (ll i = coef.size() - 1; i >= 0; i--) { ret = ret * t + coef[i]; }
    return ret;
  }

  Polynomial& selfCutoff(int deg) {
    if (degree() <= deg) return *this;
    coef.resize(deg + 1);
    normalize();
    return *this;
  }

  Polynomial cutoff(int deg) const {
    int new_deg = min(deg, degree());
    vector<T> new_coef(new_deg + 1);
    for (int i = 0; i <= new_deg; i++) new_coef[i] = coef[i];
    return Polynomial(move(new_coef));
  }

  T selfDivideLinear(T c) {
    if (coef.empty()) { return (T)0; }
    T x = coef.back();
    for (ll i = coef.size() - 2; i >= 0; i--) {
      T y = coef[i] + x * c;
      coef[i] = x;
      x = y;
    }
    coef.pop_back();
    return x;
  }

  pair<Polynomial, T> divideLinear(T c) const {
    Polynomial ret(*this);
    T t = ret.selfDivideLinear(c);
    return {ret, t};
  }

  // p.divmod(q) returns pair (d, r),
  // where p = qd + r, degree(r) < degree(q).
  // Either of the following should hold, but no check is done.
  //   - T is a field, or
  //   - the coefficient of the highest degree of q is (T)1.
  pair<Polynomial, Polynomial> divmod(const Polynomial& q) const {
    int this_deg = degree();
    int q_deg = q.degree();
    if (q_deg == 0) {
      vector<T> new_coef(coef);
      for (ll i = 0; i <= this_deg; i++) { new_coef[i] /= q.coef[0]; }
      return {Polynomial(move(new_coef)), Polynomial()};
    }
    int div_deg = this_deg - q_deg;
    if (div_deg < 0) { return { (T)0, *this }; }
    int mod_deg = q_deg - 1;
    vector<T> div_coef(div_deg + 1);
    vector<T> mod_coef(coef);
    DLOGK_LIB(div_deg, mod_deg);
    DLOGK_LIB(div_coef, mod_coef);
    for (int i = 0; i <= div_deg; i++) {
      T c = mod_coef[this_deg - i] / q.coef[q_deg];
      div_coef[div_deg - i] = c;
      for (int j = 0; j <= q_deg; j++) {
        mod_coef[this_deg - i - j] -= c * q.coef[q_deg - j];
      }
      DLOGK_LIB(i, div_coef, mod_coef);
    }
    mod_coef.resize(mod_deg + 1);
    return { Polynomial(div_coef), Polynomial(mod_coef) };
  }

  Polynomial divFormalSeries(const Polynomial& q, int n) const {
    vector<T> ret(n + 1);
    int p_deg = degree();
    int q_deg = q.degree();
    for (int i = 0; i <= n; i++) {
      T s = i <= p_deg ? coef[i] : (T)0;
      for (int k = 1; k <= min(i, q_deg); k++) {
        s -= ret[i - k] * q.coef[k];
      }
      ret[i] = q.coef[0] == (T)1 ? s : s / q.coef[0];
    }
    return Polynomial(move(ret));
  }

  T subBostanMori(const Polynomial& o, ll n) const {
    auto rev = [](vector<T> &f) -> void {
      for (int i = 1; i < (int)f.size(); i += 2) { f[i] = -f[i]; }
    };
    auto shift = [](vector<T> &f, int bit) -> void {
      int d = ((int)f.size() + 1 - bit) >> 1;
      for (int i = 0; i < d; i++) f[i] = f[(i << 1) | bit];
      f.resize(d);
    };
    if (o.coef[0] != (T)1) {
      throw runtime_error("subBostanMori: o.coef[0] should be 1.");
    }
    if (degree() >= o.degree()) {
      throw runtime_error("subBostanMori: broken: degree() < o.degree()");
    }
    vector<T> p(coef), q(o.coef), q_rev(o.coef);
    rev(q_rev);
    for (; n; n >>= 1) {
      p = coef_conv(move(p), q_rev);
      shift(p, n % 2);
      q = coef_conv(move(q), move(q_rev));
      shift(q, 0);
      q_rev = q; rev(q_rev);
    }
    return p[0] / q[0];
  }

  friend T bostanMori(const Polynomial& p, const Polynomial& q, ll n) {
    return p.subBostanMori(q, n);
  }


  Polynomial& operator +=(T t) {
    coef[0] += t;
    normalize();
    return *this;
  }
  Polynomial& operator -=(T t) { return *this += (-t); }
  Polynomial& operator *=(T t) {
    if (t == (T)0) {
      coef.resize(0);
    }else {
      for (int i = 0; i < (int)coef.size(); i++) coef[i] *= t;
    }
    return *this;
  }
  Polynomial operator +(T t) const { return Polynomial(*this) += t; }
  Polynomial operator -(T t) const { return Polynomial(*this) -= t; }
  Polynomial operator *(T t) const { return Polynomial(*this) *= t; }
  friend Polynomial operator +(T t, const Polynomial& p) { return p + t; }
  friend Polynomial operator -(T t, const Polynomial& p) { return (-p) + t; }
  friend Polynomial operator *(T t, const Polynomial& p) { return p * t; }


  Polynomial& operator +=(const SP& o) {
    if (degree() < o.degree()) { coef.resize(o.degree() + 1); }
    for (auto [i, t] : o.coef) { coef[i] += t; }
    normalize();
    return *this;
  }

  Polynomial& operator -=(const SP& o) { 
    if (degree() < o.degree()) { coef.resize(o.degree() + 1); }
    for (auto [i, t] : o.coef) { coef[i] -= t; }
    normalize();
    return *this;
  }

  Polynomial& selfMult(const SP& o, int lim = -1) {
    if (coef.empty()) return *this;
    if (o.coef.empty()) { coef.resize(0); return *this; }
    int dd = degree() + o.degree();
    if (lim < 0 || dd < lim) lim = dd;
    auto old_coef = move(coef);
    coef = vector<T>(lim + 1);
    for (auto [i, t] : o.coef) {
      for (int j = 0; j < (int)old_coef.size() && j <= lim - i; j++) {
        coef[i + j] += t * old_coef[j];
      }
    }
    normalize();
    return *this;
  }

  Polynomial mult(const SP& o, int lim = -1) const {
    Polynomial p(*this);
    return p.selfMult(o, lim);
  }

  Polynomial& operator *=(const SP& o) { return selfMult(o, -1); }

  // the constant term of o should have the inverse.
  Polynomial& selfDivFPS(const SP& o, int lim = -1) {
    if (o.coef.empty()) throw runtime_error("selfDivFPS: o.coef.empty");
    auto [i, t0] = o.coef.front();
    if (i != 0) throw runtime_error("selfDivFPS: no constant factor");
    T invt = (T)1 / t0;
    if (invt * t0 != (T)1) throw runtime_error("selfDivFPS: no inverse");
    if (lim < 0) lim = degree();
    else if (lim > degree()) coef.resize(lim + 1);
    auto work = move(coef);
    coef = vector<T>(lim + 1);
    for (int j = 0; j <= lim; j++) {
      coef[j] = work[j] * invt;
      for (auto [k, t] : o.coef) {
        if (j + k > lim) break;
        work[j + k] -= coef[j] * t;
      }
    }
    normalize();
    return *this;
  }

  Polynomial divFPS(const SP& o, int lim = -1) const {
    Polynomial p(*this);
    return p.selfDivFPS(o, lim);
  }

  Polynomial operator +(SP t) const { return Polynomial(*this) += t; }
  Polynomial operator -(SP t) const { return Polynomial(*this) -= t; }
  Polynomial operator *(SP t) const { return Polynomial(*this) *= t; }
  friend Polynomial operator +(SP t, const Polynomial& p) { return p + t; }
  friend Polynomial operator -(SP t, const Polynomial& p) { return (-p) + t; }
  friend Polynomial operator *(SP t, const Polynomial& p) { return p * t; }


  friend ostream& operator<< (ostream& os, const Polynomial& p) {
    os << p.coef;
    return os;
  }

  static const SparsePoly<T> X;
  static SparsePoly<T> Xn(int n) { return SparsePoly<T>::Xn(n); }

};
template<typename T, int use_fft>
const SparsePoly<T> Polynomial<T, use_fft>::X({{1,1}});


template<typename T>
struct SparsePoly {   // Sparse Polynomial
  using coef_elm_t = pair<ll, T>;      
  using coef_t = vector<coef_elm_t>;   
  coef_t coef;      
  // {k, t} in coef means t*X^k.  all t should not be (T)0
  // Thus, 0 (as polynomial) should be represented by the empty vector.

  // degree of 0 (as polynomial) is -1
  int degree() const {
    if (coef.empty()) return -1;
    return coef.back().first;
  }
  void normalize() {
    while (!coef.empty() && coef.back().second == (T)0) coef.pop_back();
  }

  SparsePoly() : coef() {}
  SparsePoly(const SparsePoly& sp) : coef(sp.coef) {}
  SparsePoly(SparsePoly&& sp) : coef(move(sp.coef)) {}
  SparsePoly(T t) : coef() { if (t != (T)0) { coef.emplace_back(0, t); } }

  // argument coef_ should be sorted and should not contain (T)0
  SparsePoly(const coef_t& coef_) : coef(coef_) { normalize(); }
  SparsePoly(coef_t&& coef_) : coef(move(coef_)) { normalize(); }
  SparsePoly(initializer_list<coef_elm_t> init) : coef(init) { normalize(); }

  void from_vec(const vector<T>& vec) {
    coef.resize(0);
    for (size_t i = 0; i < vec.size(); i++) {
      if (vec[i] != (T)0) { coef.emplace_back(i, vec[i]); }
    }
    normalize();
  }

  SparsePoly(const vector<T>& vec) { from_vec(vec); }
  template<int use_fft>
  SparsePoly(const Polynomial<T, use_fft>& p) { from_vec(p.coefVec()); }

  SparsePoly& operator=(const SparsePoly& sp) {
    coef = sp.coef;
    return *this;
  }
  SparsePoly& operator=(SparsePoly&& sp) {
    coef = move(sp.coef);
    return *this;
  }
  SparsePoly& operator=(T t) {
    if (t != (T)0) { coef.emplace_back(0, t); }
    normalize();
    return *this;
  }
  SparsePoly& operator=(const coef_t& coef_) {
    coef = coef_; normalize();
    return *this;
  }
  SparsePoly& operator=(coef_t&& coef_) {
    coef = move(coef_); normalize();
    return *this;
  }
  SparsePoly& operator=(initializer_list<coef_elm_t> init) {
    coef = init;
    normalize();
    return *this;
  }
  SparsePoly& operator=(const vector<T>& vec) {
    from_vec(vec);
    return *this;
  }
  template<int use_fft>
  SparsePoly& operator=(const Polynomial<T, use_fft>& p) {
    from_vec(p.coefVec());
    return *this;
  }

  /*
  static SparsePoly getX() { return SparsePoly({{1, 1}}); }
  static SparsePoly getXn(int n) { return SparsePoly({{n, 1}}); }
  */

  coef_t _plus_minus(const coef_t& a, const coef_t& b, int flag) const {
    coef_t ret;
    int i = 0, j = 0;
    while (true) {
      auto [ka, ta] = i < (int)a.size() ? a[i] : coef_elm_t(LLONG_MAX, 0);
      auto [kb, tb] = j < (int)b.size() ? b[j] : coef_elm_t(LLONG_MAX, 0);
      if (flag != 1) tb = -tb;
      if (ka < kb) {
        ret.emplace_back(ka, ta);
        i++;
      }else if (ka > kb) {
        ret.emplace_back(kb, tb);
        j++;
      }else if (ka == LLONG_MAX) { break; }
      else {
        T tt = ta + tb;
        if (tt != (T)0) ret.emplace_back(ka, tt);
        i++; j++;
      }
    }
    return ret;
  }

  SparsePoly operator -() const {
    coef_t new_coef;
    for (const auto& [k, t] : coef) new_coef.emplace_back(k, -t);
    return SparsePoly(new_coef);
  }
  SparsePoly& operator +=(const SparsePoly& o) {
    coef = _plus_minus(coef, o.coef, 1);
    return *this;
  }
  SparsePoly& operator -=(const SparsePoly& o) {
    coef = _plus_minus(coef, o.coef, 2);
    return *this;
  }
  SparsePoly& operator *=(const SparsePoly& o) {
    coef_t new_coef;
    for (const auto& [ko, to]: o.coef) {
      coef_t shifted;
      for (auto& [k, t] : coef) { shifted.emplace_back(k + ko, t * to); }
      new_coef = _plus_minus(new_coef, shifted, 1);
    }
    coef = move(new_coef);
    return *this;
  }
  SparsePoly operator +(const SparsePoly& o) const {
    return SparsePoly(*this) += o;
  }
  SparsePoly operator -(const SparsePoly& o) const {
    return SparsePoly(*this) -= o;
  }
  SparsePoly operator*(const SparsePoly& o) const {
    return SparsePoly(*this) *= o;
  }

  bool operator ==(const SparsePoly& o) const { return coef == o.coef; }
  bool operator !=(const SparsePoly& o) const { return coef != o.coef; }

  friend SparsePoly operator+(const SparsePoly& sp, T t) {
    return SparsePoly(sp) += t;
  }
  friend SparsePoly operator-(const SparsePoly& sp, T t) {
    return SparsePoly(sp) -= t;
  }
  friend SparsePoly operator*(const SparsePoly& sp, T t) {
    return SparsePoly(sp) *= t;
  }
  friend SparsePoly operator+(T t, const SparsePoly& sp) { return sp + t; }
  friend SparsePoly operator-(T t, const SparsePoly& sp) { return -(sp - t); }
  friend SparsePoly operator*(T t, const SparsePoly& sp) { return sp * t; }

  friend ostream& operator<<(ostream& os, const SparsePoly& sp) {
    if (sp.coef.empty()) {
      cout << "0";
    }else {
      bool first = true;
      for (const auto& [k, t] : sp.coef) {
        if (first) first = false;
        else cout << " ";
        if (k == 0) cout << t;
        else if (k == 1) cout << "+ " << t << "X";
        else cout << "+ " << t << "X^" << k;
      }
    }
    return os;
  }

  static const SparsePoly X;
  static SparsePoly Xn(int n) { return SparsePoly({{n,1}}); }

};
template<typename T>
const SparsePoly<T> SparsePoly<T>::X({{1,1}});

using PolyLL = Polynomial<ll, 2>;
using PolyFpA = Polynomial<FpA, 0>;
using PolyFpB = Polynomial<FpB, 1>;

// ---- end polynomial.cc

// @@ !! LIM -- end mark --
#line 7 "polynomial_skel.cc"

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  double et = get_time_sec();

  {
    using PolyDouble = Polynomial<double, 0>;

    PolyLL p1({-2, 0, 1});
    PolyLL p2({2, -1, 3, 2});

    assert(p1 == p1);
    assert(p1 != p2);

    assert(p1.degree() == 2 && p2.degree() == 3);
    assert(p1.getCoef(0) == -2 && p1.getCoef(1) == 0 && p1.getCoef(2) == 1);

    assert(p1 + p2 == PolyLL({0, -1, 4, 2}));
    assert(p2 + p1 == PolyLL({0, -1, 4, 2}));
    assert(p1 - p2 == PolyLL({-4, 1, -2, -2}));
    assert(p2 - p1 == PolyLL({4, -1, 2, 2}));
    assert(-p1 == PolyLL({2, 0, -1}));
    assert(PolyDouble(12.3) ==
           PolyDouble({12.3, 1.0}) - PolyDouble({0.0, 1.0}));
    PolyLL p3({1, 2, 3});
    PolyLL p4(p3);
    p3 *= PolyLL({0, 0, 0, 1});
    p4 += p3;
    assert(p4 == PolyLL({1, 2, 3, 1, 2, 3}));
    
    PolyLL p5({-4, 2, -4, -5, 3, 2});
    assert(p1 * p2 == p5);
    assert(p2 * p1 == p5);

    assert(10LL + p1 == PolyLL({8, 0, 1}));
    assert(p1 + 10LL == PolyLL({8, 0, 1}));
    assert(10LL - p1 == PolyLL({12, 0, -1}));
    assert(p1 - 10LL == PolyLL({-12, 0, 1}));
    assert(10LL * p1 == PolyLL({-20, 0, 10}));
    assert(p1 * 10LL == PolyLL({-20, 0, 10}));

    for (ll x = -3; x <= 3; x++) {
      assert(p2.atval(x) == 2 + (-1) * x + 3 * x*x + 2 * x*x*x);
    }

    const auto& X = SparsePoly<ll>::X;
    assert((X - 1LL) * (X - 1LL) == (X * X) - 2LL * X + 1LL);

    using Fp = FpG<2>;
    auto Y = Polynomial<Fp, 0>({0,1});
    assert((Y - Fp(1)) * (Y - Fp(1)) == (Y * Y) + Fp(1));

    PolyLL pzero;
    assert(2 * p5 != p5);
    assert(p5 + pzero == p5);
    assert(p5 - pzero == p5);
    assert(p5 * pzero == pzero);
    assert(pzero + p5 == p5);
    assert(pzero - p5 == -p5);
    assert(pzero * p5 == pzero);
    DLOGK(p5 - p5);
    DLOGK(pzero);
    assert(p5 - p5 == pzero);
    assert(p5 * 0 == pzero);
    assert(p5 + 0 == p5);
    assert(0 * p5 == pzero);
    assert(0 + p5 == p5);

  }
  {
    SparsePoly<ll> X = SparsePoly<ll>::X;

    vector<ll> vec1({1, 0, 2});
    SparsePoly<ll> sp1(vec1);
    SparsePoly<ll> sp1a({{0,1}, {2,2}});
    // DLOGK(sp1, sp1a);
    assert(sp1 == sp1a);
    Polynomial<ll, 0> pol1(vec1);
    SparsePoly<ll> sp2(pol1);
    assert(sp1 == sp2);
    sp1 = vector<ll>({4, 1});
    assert(sp1 == SparsePoly<ll>({{0,4}, {1,1}}));
    sp1 = {{5, 2}};
    assert(sp1 == 2*X*X*X*X*X);
    sp1 = vector<pair<ll, ll>>({{2, -3}});
    assert(sp1 == -3*X*X);
  }

  cerr << "1 " << get_time_sec() - et << endl;
  et = get_time_sec();
  {
    using Fp = FpA;
    using Pol = Polynomial<Fp, 0>;
    Pol p1;
    assert(p1.degree() == -1);
    Pol p2(Fp(10));
    assert(p2.degree() == 0 && p2.getCoef(0) == Fp(10));
    vector<Fp> v1({2, 3, 4});
    auto v2(v1);
    Pol p3(v1);
    Pol p4(move(v2));
    Pol p5({2, 3, 4});
    assert(p3 == p4 && p3 == p5 && !(p4 != p5));
    Pol p6(p3);
    Pol p7(move(p5));
    Pol p8; p8 = p3;
    Pol p9; p9 = move(p4);
    assert(p6 == p7 && p6 == p8 && p6 == p9);
    Pol p10; p10 = Fp(10);
    assert(p10 == p2);

    vector<Fp> v3({1, 2, 3, 4, 5});
    Pol p11(v3);
    Pol p11cp(p11);
    Pol p12({6, 7});
    p11 = p11cp; p11 += p12; assert(p11 == p11cp + p12);
    p11 = p11cp; p11 -= p12; assert(p11 == p11cp - p12);
    p11 = p11cp; p11 *= p12; assert(p11 == p11cp * p12);
    p11 = p11cp; p11 += Fp(10); assert(p11 == p11cp + Fp(10));
    p11 = p11cp; p11 -= Fp(10); assert(p11 == p11cp - Fp(10));
    p11 = p11cp; p11 *= Fp(10); assert(p11 == p11cp * Fp(10));
    p11 = p11cp; 
    assert(p11 + Fp(10) == Fp(10) + p11);
    assert(p11 - Fp(10) == -(Fp(10) - p11));
    assert(p11 * Fp(10) == Fp(10) * p11);

    stringstream ss;
    ss << p11;
    assert(ss.str() == "[1, 2, 3, 4, 5]");
    
  }
  cerr << "2 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Fp = FpB;
    using TupF = tuple<vector<Fp>, vector<Fp>, vector<Fp>>;
    vector<TupF> tests1({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {2,1}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,3},       {9},              {-2}},
        {{-1,3},      {9},              {}},
        {{-1,3},      {},               {3}},
        {{-1,-7},     {},               {}},
        {{3},         {4,3,2,1},        {}}
      });
    for (auto [vq, vd, vm] : tests1) {
      PolyFpB q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      DLOGK(p, q, d, m, dd, mm);
      assert(d == dd && m == mm);
      if (q.degree() == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.getCoef(0) / q.getCoef(1));
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == q.getCoef(1) * d && PolyFpB(mmm) == m);
      }
    }

    using TupL = tuple<vector<ll>, vector<ll>, vector<ll>>;
    vector<TupL> tests2({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{2,4,6},     {-1,0,0,0,1},     {1,-3}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,5},       {9,0,-2},         {3}},
        {{4,1},       {9},              {-2}},
        {{-3,1},      {9},              {}},
        {{-8,1},      {},               {3}},
        {{5,1},       {},               {}},
      });
    for (auto [vq, vd, vm] : tests2) {
      PolyLL q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
      if (q.degree() == 1 && q.getCoef(1) == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.getCoef(0));
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == d && PolyLL(mmm) == m);
      }
    }

    using Pol = Polynomial<double, 0>;
    using Tup = tuple<vector<double>, vector<double>, vector<double>>;
    vector<Tup> tests3({
        {{0,0,0,2},  {-3,4,1},   {1,-3}},
        {{4,3,2,1},   {4,3,2,1}, {1,-3}}
      });
    for (auto [vq, vd, vm] : tests3) {
      Pol q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
    }

  }
  cerr << "3 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Fp = FpB;
    vector<Fp> v1, v2;
    const int sz = 100;
    for (int i = 0; i < sz + 1; i++) {
      v1.push_back(randrange(0, primeB));
      v2.push_back(randrange(0, primeB));
    }
    v1[sz] = v2[sz] = 1;
    auto pol1X = Polynomial<Fp, 0>(v1);
    auto pol2X = Polynomial<Fp, 0>(v2);
    auto pol1Y = Polynomial<Fp, 1>(v1);
    auto pol2Y = Polynomial<Fp, 1>(v2);
    auto pol3X = pol1X * pol2X;
    auto pol3Y = pol1Y * pol2Y;
    assert(pol3X.degree() == 2 * sz);
    assert(pol3Y.degree() == 2 * sz);
    for (ll i = 0; i <= 2 * sz; i++) {
      assert(pol3X.getCoef(i) == pol3Y.getCoef(i));
    }
  }
  cerr << "4 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    vector<ll> v1, v2;
    const int sz = 100;
    for (int i = 0; i < sz + 1; i++) {
      v1.push_back(randrange(0, 1LL << 30));
      v2.push_back(randrange(0, 1LL << 30));
    }
    v1[sz] = v2[sz] = 1;
    auto pol1X = Polynomial<ll, 0>(v1);
    auto pol2X = Polynomial<ll, 0>(v2);
    auto pol1Y = Polynomial<ll, 2>(v1);
    auto pol2Y = Polynomial<ll, 2>(v2);
    auto pol3X = pol1X * pol2X;
    auto pol3Y = pol1Y * pol2Y;
    assert(pol3X.degree() == 2 * sz);
    assert(pol3Y.degree() == 2 * sz);
    for (ll i = 0; i <= 2 * sz; i++) {
      assert(pol3X.getCoef(i) == pol3Y.getCoef(i));
    }
  }
  cerr << "5 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Pol = PolyLL;
    const auto& X = SparsePoly<ll>::X;
    Pol p1 = Pol(1), p2 = Pol(1) - X;
    auto a = p1.divFormalSeries(p2, 70);
    for (ll i = 0; i <= 70; i++) {
      assert(a.getCoef(i) == 1);
      assert(bostanMori(p1, p2, 1) == 1);
    }
  }
  cerr << "6 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Fp = FpB;
    using Pol = PolyFpB;
    const auto& X = Pol::X;
    Pol p1 = Pol(1), p2 = Pol(1) - X - X*X;
    assert(bostanMori(p1, p2, 0) == Fp(1));
    assert(bostanMori(p1, p2, 1) == Fp(1));
    assert(bostanMori(p1, p2, 2) == Fp(2));
    assert(bostanMori(p1, p2, 10) == 89);
    auto a = p1.divFormalSeries(p2, 10);
    assert(a.coefVec() == vector<Fp>({1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}));

    for (ll t = 0; t < 10; t++) {
      ll degP = randrange(0, 100);
      ll degQ = degP + randrange(1, 100);
      ll lim = 10;
      vector<Fp> coefP(degP + 1);
      vector<Fp> coefQ(degQ + 1);
      for (ll i = 0; i < degP + 1; i++) coefP[i] = randrange(-lim, lim + 1);
      for (ll i = 1; i < degQ + 1; i++) coefQ[i] = randrange(-lim, lim + 1);
      coefQ[0] = 1;
      while (coefQ[degQ] == Fp(0)) coefQ[degQ] = randrange(-lim, lim + 1);
      Pol p(coefP), q(coefQ);
      ll degR = 2 * degQ;
      auto r = p.divFormalSeries(q, degR);
      assert(r.getCoef(degR) == bostanMori(p, q, degR));
      for (ll i = 0; i < 10; i++) {
        ll idx = randrange(0, degR);
        assert(r.getCoef(idx) == bostanMori(p, q, idx));
      }
    }
  }
  cerr << "7 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using SP = SparsePoly<ll>;
    SP sp1;
    SP sp2({{0, 1}, {1, -3}, {2, 3}, {3, -1}});
    SP sp3({{1, 1}});
    SP sp4 = SP::X;
    SP sp52 = SP::Xn(2);
    SP sp53 = SP::Xn(3);
    SP sp6 = 1LL - sp4;
    SP sp7 = sp6 * sp6 * sp6;
    SP sp8 = 1LL - 3 * sp4 + 3 * sp52 - sp53;
    assert(sp8 * 0 == sp1);
    assert(sp8 - sp8 == sp1);
    assert(sp2 == sp8);
    assert(sp2 == sp7);

    assert(PolyLL({1,2}) - SP::Xn(5) == PolyLL({1,2,0,0,0,-1}));
    assert(PolyLL({10,11,12}) - 12 * SP::Xn(2) == PolyLL({10,11}));
    assert(PolyLL() * SP() == PolyLL());
    assert(SP() * PolyLL() == PolyLL());
    assert(PolyLL() * SP::Xn(2) == PolyLL());
    assert(SP::Xn(2) * PolyLL() == PolyLL());
  }
  {
    using SP = SparsePoly<ll>;
    PolyLL p1({1, 2, 3});
    SP sp1 = 4LL - SP::Xn(2);
    assert(p1 + sp1 == PolyLL({5, 2, 2}));
    assert(p1 - sp1 == PolyLL({-3, 2, 4}));
    assert(p1 * sp1 == PolyLL({4, 8, 11, -2, -3}));
    PolyLL p2({1, 2, 3, 4, 5});
    p2 = sp1;
    assert(p2 == PolyLL(sp1));
    p2 = 0;
    assert(p2 == PolyLL());
    PolyLL p4({1, 2, 3, 0, 5});
    assert(p4.cutoff(2) == PolyLL({1, 2, 3}));
    assert(p4.cutoff(3) == PolyLL({1, 2, 3}));
    assert(p4.cutoff(10) == p4);
    assert(p4.cutoff(0) == 1);
    assert(p4.cutoff(-1) == 0);
    PolyLL p5;
    p5 = p4; p5.selfCutoff(2); assert(p5 == PolyLL({1, 2, 3}));
    p5 = p4; p5.selfCutoff(3); assert(p5 == PolyLL({1, 2, 3}));
    p5 = p4; p5.selfCutoff(10); assert(p5 == p4);
    p5 = p4; p5.selfCutoff(0); assert(p5 == 1);
    p5 = p4; p5.selfCutoff(-1); assert(p5 == 0);

    PolyLL p10({1,2,3,4,5,6,7});
    SP sp10({{0,1}, {2,-1}, {4,2}});
    assert(p10.mult(sp10, 0) == (p10 * sp10).cutoff(0));
    assert(p10.mult(sp10, 2) == (p10 * sp10).cutoff(2));
    assert(p10.mult(sp10, 10) == (p10 * sp10).cutoff(10));
    assert(p10.mult(sp10, 15) == (p10 * sp10).cutoff(15));
  }

  {
    using SP = SparsePoly<ll>;
    ll rep = 1000;
    for (ll z = 0; z < rep; z++) {
      ll deg1 = randrange(0, 10);
      vector<ll> v1(deg1 + 1);
      for (ll i = 0; i <= deg1; i++) v1[i] = randrange(-20, 20);
      PolyLL p1(v1);
      ll size2 = randrange(0, 5);
      vector<pair<ll, ll>> v2;
      ll cur = -1;
      for (ll i = 0; i < size2; i++) {
        cur += randrange(1, 4);
        v2.emplace_back(cur, randrange(-20, 20));
      }
      SP sp2(v2);
      PolyLL p3 = p1.mult(sp2);
      PolyLL p4 = p1 * PolyLL(sp2);
      assert(p3 == p4);
      PolyLL p5 = p1.mult(sp2, deg1);
      assert (p5 == p4.cutoff(deg1));

      ll y = randrange(0,2) == 0 ? 1LL : -1LL;
      SP sp3 = sp2 - PolyLL(sp2).getCoef(0) + y;
      
      PolyLL p6 = p1.divFPS(sp3);
      PolyLL p7 = (p6 * sp3 - p1).cutoff(p1.degree());
      assert(p7 == 0);
      PolyLL p8 = p1.divFPS(sp3, 4);
      PolyLL p9 = (p8 * sp3 - p1).cutoff(min(4, sp3.degree()));
      assert(p9 == 0);
    }
  }



  cout << "test done." << endl;

  return 0;
}

