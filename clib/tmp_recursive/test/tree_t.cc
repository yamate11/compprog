#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define SIZE(v) ((ll)((v).size()))
using u64 = unsigned long long;

// @@ !! LIM(mod debug tree)

// ---- inserted library file algOp.cc
#line 105 "../algOp.cc"

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

namespace tartan_detail {
  template <template <class...> class Trait, class Enabler, class... Args>
  struct is_detected : false_type{};

  template <template <class...> class Trait, class... Args>
  struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : true_type{};
}

template <template <class...> class Trait, class... Args>
using is_detected = typename tartan_detail::is_detected<Trait, void, Args...>::type;

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
//     It guarantees that max(|s|, |t|) <= max(|a| / g, |b| / g)   (when g != 0)
//     Note that gcd(a, 0) == gcd(0, a) == a.
tuple<ll, ll, ll> eGCD(ll a, ll b) {
  ll sa = a < 0 ? -1 : 1;
  ll ta = 0;
  ll za = a * sa;
  ll sb = 0;
  ll tb = b < 0 ? -1 : 1;
  ll zb = b * tb;
  while (zb != 0) {
    ll q = za / zb;
    ll r = za % zb;
    za = zb;
    zb = r;
    ll new_sb = sa - q * sb;
    sa = sb;
    sb = new_sb;
    ll new_tb = ta - q * tb;
    ta = tb;
    tb = new_tb;
  }
  return {za, sa, ta};
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
#line 38 "../mod.cc"

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

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

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

// ---- inserted library file debug.cc
#line 42 "../debug.cc"
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

// ---- inserted library file tree.cc
#line 101 "../tree.cc"

struct function_error : runtime_error {
  function_error(const string& msg) : runtime_error(msg) {}
};

struct Tree {

  struct pe_t {
    int peer;
    int edge;
    pe_t(int peer_ = -1, int edge_ = -1) : peer(peer_), edge(edge_) {}
    static const pe_t end_object;
  };

  struct nbr_t {
    int parent_idx;                 // pe[parent_idx] is the parent
    vector<pe_t> pe;
    nbr_t() : parent_idx(-1), pe() {}
  };

  template<bool get_peer>
  struct nbr_iterator {
    const nbr_t& body;
    int pe_idx;
    explicit nbr_iterator(const nbr_t& body_, int pe_idx_) : body(body_), pe_idx(pe_idx_) {
      if (pe_idx == body.parent_idx) pe_idx++;
    }
    auto operator*() const -> typename conditional<get_peer, int, const pe_t&>::type {
      if constexpr (get_peer) return body.pe[pe_idx].peer;
      else                    return body.pe[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      if (pe_idx == body.parent_idx) pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer>
  struct children_view {
    const nbr_t& body;
    children_view(const nbr_t& body_) : body(body_) {}
    nbr_iterator<get_peer> begin() const { return nbr_iterator<get_peer>(body, 0); }
    nbr_iterator<get_peer> end() { return nbr_iterator<get_peer>(body, std::ssize(body.pe)); }
  };

  int numNodes;
  int root;
  vector<nbr_t> _nbr;
  vector<pair<int, int>> _edges;   // (x, y) in _edges => x < y
  vector<int> _parent;             // _parent[root] == -1
  vector<int> _stsize;
  vector<int> _depth;
  unordered_map<long long, int> _edge_idx;
  vector<vector<int>> _pPnt;   
          // _pPnt[0][n] == parent of n (or root if n is root)
          // _pPnt[t][n] == parent^{2^t}[n]
  vector<int> _euler_in;
  vector<int> _euler_out;
  vector<pair<int, bool>> _euler_edge;

  constexpr static bool use_depth = true;
  constexpr static bool use_stsize = true;
  constexpr static bool use_euler = true;

  Tree(int numNodes_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {
    if (numNodes == 1) _set_parent();
  }

  int add_edge(int x, int y) {
    int i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].pe.emplace_back(y, i);
    _nbr[y].pe.emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()

    _nbr[root].parent_idx = ssize(_nbr[root].pe);

    if constexpr (use_depth) _depth.resize(numNodes);
    if constexpr (use_stsize) _stsize.resize(numNodes);
    if constexpr (use_euler) {
      _euler_in.resize(numNodes);
      _euler_out.resize(numNodes);
      _euler_edge.resize(2 * numNodes);
    }
    int euler_idx = 0;

    auto dfs = [&](auto rF, int nd, int pt, int edge) -> void {
      if constexpr (use_depth) _depth[nd] = pt == -1 ? 0 : _depth[pt] + 1;
      if constexpr (use_stsize) _stsize[nd] = 1;
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, nd < pt};
        _euler_in[nd] = euler_idx;
        euler_idx++;
      }
      for (int i = 0; i < ssize(_nbr[nd].pe); i++) {
        auto [c_id, c_eg] = _nbr[nd].pe[i];
        if (c_id == pt) _nbr[nd].parent_idx = i;
        else {
          rF(rF, c_id, nd, c_eg);
          if constexpr (use_stsize) _stsize[nd] += _stsize[c_id];
        }
      }
      if constexpr (use_euler) {
        _euler_edge[euler_idx] = {edge, pt < nd};
        _euler_out[nd] = euler_idx;
        euler_idx++;
      }
    };

    dfs(dfs, root, -1, numNodes - 1);
  }

  pe_t parent_pe(int nd) { return _nbr[nd].pe[_nbr[nd].parent_idx]; }
  int parent(int nd) { return nd == root ? -1 : parent_pe(nd).peer; }
  int num_children(int nd) { return _nbr[nd].pe.size() - (_nbr[nd].parent_idx == (int)_nbr[nd].pe.size() ? 0 : 1); }
  pe_t child_pe(int nd, int idx) { return _nbr[nd].pe[idx < _nbr[nd].parent_idx ? idx : idx + 1]; }
  int child(int nd, int idx) { return child_pe(nd, idx).peer; }
  int child_edge(int nd, int idx) { return child_pe(nd, idx).edge; }
  auto children_pe(int nd) { return children_view<false>(_nbr[nd]); }
  auto children(int nd) { return children_view<true>(_nbr[nd]); }

  int stsize(int nd) {
    if constexpr (use_stsize) return _stsize[nd];
    else throw function_error("use_stsize should be set to call stsize.");
  }

  int depth(int nd) {
    if constexpr (use_depth) return _depth[nd];
    else throw function_error("use_depth should be set to call depth.");
  }

  long long _enc_node_pair(int x, int y) { return (x + 1) * (numNodes + 1) + (y + 1); }

  int edge_idx(int x, int y) {
    if (_edge_idx.empty()) {
      for (int i = 0; i < ssize(_edges); i++) {
        auto [xx, yy] = _edges[i];
        _edge_idx[_enc_node_pair(xx, yy)] = i;
        _edge_idx[_enc_node_pair(yy, xx)] = i;
      }
    }
    auto it = _edge_idx.find(_enc_node_pair(x, y));
    return it == _edge_idx.end() ? -1 : it->second;
  }

  pair<int, int> nodes_of_edge(int e) { return _edges[e]; }

  void _set_euler() {
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    vector<pair<int, int>> stack{{root, -1}};
    int idx = 0;
    while (not stack.empty()) {
      auto& [nd, cidx] = stack.back();
      if (cidx == -1) _euler_in[nd] = idx++;
      cidx++;
      if (cidx < num_children(nd)) stack.emplace_back(child(nd, cidx), -1);
      else {
        _euler_out[nd] = idx++;
        stack.pop_back();
      }
    }
  }

  int euler_in(int nd) {
    if constexpr (use_euler) return _euler_in[nd];
    else throw function_error("use_euler should be set to call euler_in.");
  }

  int euler_out(int nd) {
    if constexpr (use_euler) return _euler_out[nd];
    else throw function_error("use_euler should be set to call euler_out.");
  }

  tuple<int, int, int> euler_edge(int idx) {
    if constexpr (use_euler) {
      if (idx == 0) return {numNodes - 1, -1, root};
      else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
      else {
        auto [e, b] = _euler_edge[idx];
        auto [x, y] = nodes_of_edge(e);
        if (b) swap(x, y);
        return {e, x, y};
      }
    }
    else throw function_error("use_euler should be set to call euler_out.");
  }

  void preparePPnt() {
    if (not _pPnt.empty()) return;
    vector<int> vec_parent(numNodes);
    for (int i = 0; i < numNodes; i++) vec_parent[i] = i == root ? i : parent(i);
    _pPnt.push_back(move(vec_parent));
    for (int t = 0; true; t++) {
      bool done = true;
      vector<int> vec(numNodes);
      for (int n = 0; n < numNodes; n++) {
	int m = _pPnt[t][n];
	vec[n] = _pPnt[t][m];
	if (vec[n] != m) done = false;
      }
      _pPnt.push_back(move(vec));
      if (done) break;
    }
  }

  // Lowest Common Ancestor
  int lca(int x, int y) {
    if (depth(x) > depth(y)) swap(x, y);
    int dep = depth(x);
    int yy = ancestorDep(y, dep);
    if (x == yy) return x;
    int t = 0;
    for (int q = 1; q < dep; q *= 2) t++;
    for ( ; t >= 0; t--) {
      if (_pPnt[t][x] != _pPnt[t][yy]) {
	x = _pPnt[t][x];
	yy = _pPnt[t][yy];
      }
    }
    return parent(x);
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<int> nnpath(int x, int y) {
    vector<int> ret;
    int c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    int len = (int)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

  // the ancestor of n whose depth is dep
  int ancestorDep(int x, int dep) {
    preparePPnt();
    int diff = depth(x) - dep;
    if (diff < 0) throw range_error("ancestorDep");
    for (int t = 0; diff >> t; t++) if (diff >> t & 1) x = _pPnt[t][x];
    return x;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  tuple<int, int, int, int, int> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    depth(root);   // to ensure that _depth is correctly built
    int nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    int nd1 = -1, ct0 = -1, ct1 = -1;
    int diam = 0;
    auto dfs2 = [&](auto rF, int nd, int dp, int pt) -> bool {
      // DFS from nd0, which is different from the root.
      bool ret = false;
      ll numChildren = 0;
      for (auto [cld, _e] : _nbr[nd].pe) {
        if (cld == pt) continue;
        numChildren++;
        bool bbb = rF(rF, cld, dp + 1, nd);
        ret = ret || bbb;
      }
      if (numChildren > 0) {
        if (ret) {
          if (diam % 2 == 0) {
            if (dp == diam / 2) ct0 = ct1 = nd;
          }else {
            if (dp == diam / 2) ct0 = nd;
            else if (dp == diam / 2 + 1) ct1 = nd;
          }
        }
      }else {
        if (dp > diam) {
          diam = dp;
          nd1 = nd;
          ret = true;
        }
      }
      return ret;
    };
    dfs2(dfs2, nd0, 0, -1);
    return {diam, nd0, nd1, ct0, ct1};
  }
#pragma GCC diagnostic pop

  void change_root(int newRoot) {
    _stsize.clear();
    _depth.clear();
    _edge_idx.clear();
    _euler_in.clear();
    _euler_out.clear();
    _pPnt.clear();

    root = newRoot;
    _set_parent();
  }

};

const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, int nd) -> A {
    int k = tree.num_children(nd);
    vector<M> ws(k);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (int i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (int i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, int nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    int k = tree.num_children(nd);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, int i) -> M { return m; });
}

// ---- end tree.cc

// @@ !! LIM -- end mark --
#line 9 "tree_skel.cc"


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  using TreeEdge = pair<int, int>;

  {
    vector<TreeEdge> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
    Tree t1(7);
    for (auto [x,y] : edge1) t1.add_edge(x, y);
    assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
    assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
    assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
    assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
    assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));
    assert(t1.parent(0) == -1);
    assert(t1.parent(1) == 0);
    assert(t1.parent(6) == 2);
    vector<int> v;
    for (int c : t1.children(0)) v.push_back(c);
    sort(v.begin(), v.end());
    assert(v == vector<int>({1, 2}));
    assert(t1.stsize(0) == 7);
    assert(t1.stsize(2) == 3);
    assert(t1.stsize(5) == 1);
    assert(t1.depth(0) == 0);
    assert(t1.depth(1) == 1);
    assert(t1.depth(4) == 2);
  }

  {
    using pii = pair<int, int>;
    Tree t2(3);
    t2.add_edge(0, 1);
    t2.add_edge(0, 2);
    assert(t2.edge_idx(0,1) == 0);
    assert(t2.edge_idx(2,0) == 1);
    assert(t2.nodes_of_edge(0) == pii(0, 1));
    assert(t2.nodes_of_edge(1) == pii(0, 2));
  }

  vector<TreeEdge>
    edge3({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7},
	   {6,8}, {3,9}, {9,10}, {0,11}, {11,12}, {11,13}});
  Tree t3(14);
  for (auto [x,y] : edge3) t3.add_edge(x, y);
  assert(t3.nnpath(1,5) == vector<int>({1,2,3,4,5}));
  assert(t3.nnpath(7,2) == vector<int>({7,6,5,4,3,2}));
  for (int i = 0; i <=7; i++) assert(t3.ancestorDep(7,i) == i);
  assert(t3.lca(7,8) == 6);
  assert(t3.lca(8,13) == 0);
  assert(t3.lca(7,10) == 3);

  vector<TreeEdge>
    edge4({{0,1}, {1,2}, {3,4}, {0,3}, {3,5}, {6,7}, {6,8}, {6,1}});
  Tree t4(9);
  for (auto [x,y] : edge4) t4.add_edge(x, y);
  auto sub4 = [](Tree t, int i)  {
    vector<int> v;
    for (int j = 0; j < t.num_children(i); j++) v.push_back(t.child(i, j));
    return set<int>(v.begin(), v.end());
  };
  assert(sub4(t4, 0) == set<int>({1,3}));
  assert(sub4(t4, 1) == set<int>({2,6}));
  assert(sub4(t4, 3) == set<int>({4,5}));
  assert(sub4(t4, 6) == set<int>({7,8}));
  assert(sub4(t4, 8) == set<int>());
  assert(t4.parent(0) == -1);
  assert(t4.parent(1) == 0);
  assert(t4.parent(2) == 1);
  assert(t4.parent(6) == 1);
  assert(t4.parent(8) == 6);

  {
    Tree tr(6);
    tr.add_edge(0, 1);
    tr.add_edge(0, 2);
    tr.add_edge(0, 4);
    tr.add_edge(1, 3);
    tr.add_edge(4, 5);
    auto [diam, ep0, ep1, ct0, ct1] = tr.diameter();
    assert(diam == 4 and ep0 == 3 and ep1 == 5 and ct0 == 0 and ct1 == 0);
    tr.change_root(3);
    tie (diam, ep0, ep1, ct0, ct1) = tr.diameter();
    assert(diam == 4 and ep0 == 5 and ep1 == 3 and ct0 == 0 and ct1 == 0);
    Tree tr2(7);
    tr2.add_edge(0, 1);
    tr2.add_edge(0, 2);
    tr2.add_edge(0, 4);
    tr2.add_edge(1, 3);
    tr2.add_edge(4, 5);
    tr2.add_edge(5, 6);
    tie (diam, ep0, ep1, ct0, ct1) = tr2.diameter();
    assert(diam == 5 and ep0 == 6 and ep1 == 3 and ct0 == 4 and ct1 == 0);
    tr2.change_root(4);
    tie (diam, ep0, ep1, ct0, ct1) = tr2.diameter();
    assert(diam == 5 and ep0 == 3 and ep1 == 6 and ct0 == 0 and ct1 == 4);
  }

  {
    ll repeat = 2000;
    for (ll rep = 0; rep < repeat; rep++) {
      ll N = randrange(1, 17);
      ll root = randrange(0, N);
      Tree tr(N, root);
      vector conn(N, vector<bool>(N, false));
      vector rec(N, 0LL);
      for (ll i = 1; i < N; i++) {
        ll j = randrange(0, i);
        rec[i] = j;
        conn[i][j] = conn[j][i] = true;
        if (randrange(0, 100) < 50) tr.add_edge(i, j);
        else                        tr.add_edge(j, i);
      }
      for (ll i = 0; i < N - 1; i++) {
        auto [x, y] = tr.nodes_of_edge(i);
        assert ((x == i + 1 and y == rec[i + 1]) or (x == rec[i + 1] and y == i + 1));
      }
      for (ll i = 0; i < N; i++) {
        ll cnt = 0;
        for (ll j = 0; j < N; j++) if (conn[i][j]) cnt++;
        for (ll k = 0; k < tr.num_children(i); k++) assert(conn[i][tr.child(i, k)]);
        ll sts = 1; for (ll j : tr.children(i)) sts += tr.stsize(j);
        assert(sts == tr.stsize(i));
        if (i == root) {
          assert (tr.parent(i) == -1);
          assert ((ll)(tr.num_children(i)) == cnt);
          assert (tr.depth(i) == 0);
          assert (tr.stsize(i) == N);
          assert (tr.ancestorDep(i, 0) == i);
        }else {
          assert (conn[i][tr.parent(i)]);
          assert (tr.num_children(i) + 1 == cnt);
          assert (tr.depth(i) == tr.depth(tr.parent(i)) + 1);
          vector tmp(tr.depth(i) + 1, 0LL);
          for (ll d = 0; d <= tr.depth(i); d++) tmp[d] = tr.ancestorDep(i, d);
          for (ll d = 1; d <= tr.depth(i); d++) assert (tr.parent(tmp[d]) == tmp[d - 1]);
        }
      }
      {
        for (int nd = 0; nd < N; nd++) {
          int nc = 0;
          for (int cld : tr.children(nd)) {
            assert(nd == tr.parent(cld));
            assert(cld == tr.child(nd, nc));
            auto [p, e] = tr.parent_pe(cld);
            assert(nd == p and tr.nodes_of_edge(e) == make_pair(min(nd, cld), max(nd, cld)));
            assert(tr.child_pe(nd, nc).peer == cld and tr.child_pe(nd, nc).edge == e);
            nc++;
          }
          assert(nc == tr.num_children(nd));
          int i = 0;
          for (auto [cld, e1] : tr.children_pe(nd)) {
            auto [p, e2] = tr.parent_pe(cld);
            assert(p == nd and e1 == e2);
            int e3 = tr.child_edge(nd, i);
            assert(e1 == e3);
            assert(e1 == tr.edge_idx(nd, cld));
            i++;
          }
        }
      }
      for (ll x = 0; x < N; x++) {
        for (ll y = 0; y < N; y++) {
          ll z = tr.lca(x, y);
          ll dz = tr.depth(z);
          ll dx = tr.depth(x);
          ll dy = tr.depth(y);
          assert (dx >= dz and tr.ancestorDep(x, dz) == z);
          assert (dy >= dz and tr.ancestorDep(y, dz) == z);
          if (dx > dz and dy > dz) assert(tr.ancestorDep(x, dz + 1) != tr.ancestorDep(y, dz + 1));
          const auto vec = tr.nnpath(x, y);
          for (ll i = 0; i < SIZE(vec); i++) for (ll j = i + 1; j < SIZE(vec); j++) assert(vec[i] != vec[j]);
          assert (vec[0] == x and vec.back() == y);
          for (ll i = 0; i < SIZE(vec) - 1; i++) assert(conn[vec[i]][vec[i + 1]]);
          if (conn[x][y]) assert (tr.edge_idx(x, y) == max(x, y) - 1);
          else            assert (tr.edge_idx(x, y) == -1);
        }
      }
      { // getting LCA using euler tour and sparse table
        int sz = 2 * N - 1;
        int K = countr_zero(bit_floor((u64)sz));
        vector sp_tbl(K + 1, vector(sz, -1));
        for (int i = 0; i < sz; i++) {
          auto [e, x, y] = tr.euler_edge(i);
          sp_tbl[0][i] = y;
        }
        for (int k = 1; k <= K; k++) {
          for (int i = 0; i < sz; i++) {
            if (i + (1 << k) > sz) break;
            int x = sp_tbl[k - 1][i];
            int y = sp_tbl[k - 1][i + (1 << (k - 1))];
            sp_tbl[k][i] = tr.depth(x) <= tr.depth(y) ? x : y;
          }
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int x = tr.lca(i, j);
            int y = -1, t0 = i, t1 = j;
            int i0 = tr.euler_in(i), o0 = tr.euler_out(i), i1 = tr.euler_in(j), o1 = tr.euler_out(j);
            assert(i0 != i1 and o0 != o1);
            if (i0 > i1) { swap(t0, t1); swap(i0, i1); swap(o0, o1); }
            if (o1 < o0) y = t0;
            else {
              assert(o0 < i1);
              int len = i1 - o0;
              int k = countr_zero(bit_floor((u64)len));
              int u = sp_tbl[k][o0];
              int v = sp_tbl[k][i1 - (1 << k)];
              y = tr.depth(u) <= tr.depth(v) ? u : v;
            }
            assert(x == y);
          }
      }
      {
        auto [diam, nd0, nd1, ct0, ct1] = tr.diameter();
        ll ndiam = 0;
        for (ll x = 0; x < N; x++) for (ll y = x + 1; y < N; y++) ndiam = max(ndiam, SIZE(tr.nnpath(x, y)) - 1);
        assert (diam == ndiam);
        auto path = tr.nnpath(nd0, nd1);
        assert (SIZE(path) - 1 == diam);
        if (diam % 2 == 0) assert (ct0 == ct1 and ct0 == path[diam / 2]);
        else assert(ct0 == path[diam / 2] and ct1 == path[diam / 2 + 1]);
      }
      ll newRoot = randrange(0, N);
      tr.change_root(newRoot);
      for (ll i = 0; i < N; i++) {
        ll cnt = 0;
        for (ll j = 0; j < N; j++) if (conn[i][j]) cnt++;
        for (ll j : tr.children(i)) assert(conn[i][j]);
        if (i == newRoot) {
          assert (tr.parent(i) == -1);
          assert ((ll)(tr.num_children(i)) == cnt);
          assert (tr.depth(i) == 0);
          assert (tr.stsize(i) == N);
        }else {
          assert (conn[i][tr.parent(i)]);
          assert (tr.num_children(i) + 1 == cnt);
          assert (tr.depth(i) == tr.depth(tr.parent(i)) + 1);
        }
      }
    }
  }

  // Euler Tour
  {
    int rep = 1000;
    for (int _r = 0; _r < rep; _r++) {
      int nn = randrange(1, 17);
      int root = randrange(0, nn);
      Tree tr(nn, root);
      for (int i = 1; i < nn; i++) {
        int j = randrange(0, i);
        if (randrange(0, 2) == 0) tr.add_edge(i, j);
        else                      tr.add_edge(j, i);
      }

      auto dfs = [&](auto rF, int nd) -> vector<int> {
        int ein = tr.euler_in(nd);
        int eout = tr.euler_out(nd);
        vector<int> v{ein, eout};
        if (tr.num_children(nd) == 0) {
          assert(ein + 1 == eout);
          return v;
        }else {
          for (int i : tr.children(nd)) {
            auto w = rF(rF, i);
            v.insert(v.end(), w.begin(), w.end());
          }
          sort(v.begin(), v.end());
          assert(v[0] == ein);
          assert(v.back() == eout);
          assert(ssize(v) == eout - ein + 1);
          for (int i = 0; i < ssize(v) - 1; i++) v[i + 1] = v[i] + 1;
        }
        return v;
      };
      dfs(dfs, root);
    }
  }


  // The length of the longest simple path that goes through the node
  using T5 = pair<ll, ll>;
  vector<TreeEdge> edge5({{0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,6}, {2,7}});
  vector<ll> len5({10,6,3,5,3,2,1});
  Tree t5(8);
  for (auto [x,y] : edge5) t5.add_edge(x, y);
  auto add5 = [&](T5 p1, T5 p2) -> T5 {
    ll a1 = p1.first;
    ll a2 = p2.first;
    if (a1 < a2) swap(a1, a2);
    if (a2 < p1.second) a2 = p1.second;
    if (a2 < p2.second) a2 = p2.second;
    return make_pair(a1, a2);
  };
  auto mod5 = [&](T5 p, ll n, ll c) -> T5 {
    return make_pair(p.first + len5[t5.edge_idx(n,c)], 0);
  };
  auto v5 = reroot(t5, make_pair(0, 0), add5, mod5);
  vector<ll> ans5 = {23, 23, 23, 18, 23, 21, 23, 22};
  assert(t5.numNodes == 8);
  for (ll i = 0; i < t5.numNodes; i++) {
    assert(v5[i].first + v5[i].second == ans5[i]);
  }

  // ABC160-F
  using T6 = pair<ll, ll>;
  const T6 unitT6({0, 1});
  auto fact6 = [&](const auto& recF, ll n) -> ll {
    if (n == 0) return 1;
    return n * recF(recF, n-1);
  };
  auto add6 = [&](T6 tt1, T6 tt2) -> T6 {
    ll card1; ll perm1; tie(card1, perm1) = tt1;
    ll card2; ll perm2; tie(card2, perm2) = tt2;
    ll card = card1 + card2;
    ll perm = perm1 * perm2 * fact6(fact6, card)
                  / (fact6(fact6, card1) * fact6(fact6, card2));
    T6 ret = make_pair(card, perm);
    return ret;
  };
  auto mod6 = [&](T6 t, ll n, ll c) -> T6 {
    return make_pair(t.first + 1, t.second);
  };
  vector<TreeEdge> edge6({{0,1}, {1,2}, {2,3}, {2,4}, {2,5}, {5,6}, {5,7}});
                                // input No.4
  Tree t6(8);
  for (auto [x, y] : edge6) t6.add_edge(y, x);
  auto res6 = reroot(t6, unitT6, add6, mod6);
  vector<ll> ans6({40,280,840,120,120,504,72,72}); 
  assert(t6.numNodes == 8);
  for (ll i = 0; i < 8; i++) assert(res6[i].second == ans6[i]);

  // NJPC2017-E   https://njpc2017.contest.atcoder.jp/tasks/njpc2017_e
  vector<TreeEdge> edge7({{1,0},{2,1},{1,3},{3,4},{3,5},{6,5}});
  vector<ll> time({2,3,5,1,4,6});
  for (ll rt = 0; rt < 7; rt++) {
    Tree t7(7, rt);
    for (auto [x,y] : edge7) t7.add_edge(x, y);
    using T7 = pair<ll, ll>;
    const T7 unitT7 = make_pair(0, 0);
    auto  add7 = [&](const T7& tt1, const T7& tt2) -> T7 {
      ll top1, rev1; tie(top1, rev1) = tt1;
      ll top2, rev2; tie(top2, rev2) = tt2;
      return make_pair(max(top1, top2), rev1 + rev2);
    };
    auto mod7 = [&](const T7& t, ll n, ll c) -> T7 {
      ll eid = t7.edge_idx(c, n);
      ll addRev = (edge7[eid].first == n) ? 1 : 0;
      return make_pair(t.first + time[eid], t.second + addRev);
    };
    auto res7 = reroot(t7, unitT7, add7, mod7);
    { ll x, z;
      tie(x, z) = res7[1]; assert(x == 15 && z == 4);
      tie(x, z) = res7[3]; assert(x == 10 && z == 3);
      tie(x, z) = res7[4]; assert(x == 11 && z == 2);
      tie(x, z) = res7[5]; assert(x == 12 && z == 2);
    }
  }

  { // ABC 160F rewritten

    using Fp = FpA;

    ll N = 8;
    Tree tr(N);
    tr.add_edge(0, 1);
    tr.add_edge(1, 2);
    tr.add_edge(2, 3);
    tr.add_edge(2, 4);
    tr.add_edge(2, 5);
    tr.add_edge(5, 6);
    tr.add_edge(5, 7);

    Comb<Fp> cb(N);

    using sta = pair<Fp, ll>;
    sta unit = sta{Fp(1), 0LL};
    auto myadd = [&](const sta& p1, const sta& p2) -> sta {
      return sta(p1.first * p2.first , p1.second + p2.second);
    };
    auto mod1 = [&](sta p, int nd, int cd) -> sta { return sta(p.first / cb.fact(p.second), p.second); };
    auto mod2 = [&](sta p, int nd) -> sta { return sta(p.first * cb.fact(p.second), p.second + 1); };
    auto result = reroot(tr, unit, myadd, mod1, mod2);
    vector<ll> expected{40, 280, 840, 120, 120, 504, 72, 72};
    for (ll i = 0; i < N; i++) assert(result[i].first == expected[i]);
  }


  cerr << "test done." << endl;
  return 0;
}

