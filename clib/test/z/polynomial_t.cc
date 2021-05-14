#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< mod debug convolution f:perfmeas)

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

// ---- inserted function f:gcd from util.cc

tuple<ll, ll, ll> mut_div(ll a, ll b, ll c, bool eff_c = true) {
  // auto [g, s, t] = mut_div(a, b, c, eff_c)
  //    If eff_c is true (default),
  //        g == gcd(|a|, |b|) and as + bt == c, if such s,t exists
  //        (g, s, t) == (-1, -1, -1)            otherwise
  //    If eff_c is false,                                 
  //        g == gcd(|a|, |b|) and as + bt == g           
  //    N.b.  gcd(0, t) == gcd(t, 0) == t.
  if (a == 0) {
    if (eff_c) {
      if (c % b != 0) return {-1, -1, -1};
      else            return {abs(b), 0, c / b};
    }else {
      if (b < 0) return {-b, 0, -1};
      else       return { b, 0,  1};
    }
  }else {
    auto [g, t, u] = mut_div(b % a, a, c, eff_c);
    // DLOGK(b%a, a, c, g, t, u);
    if (g == -1) return {-1, -1, -1};
    return {g, u - (b / a) * t, t};
  }
}

// auto [g, s, t] = eGCD(a, b)  --->  sa + tb == g == gcd(|a|, |b|)
//    N.b.  gcd(0, t) == gcd(t, 0) == t.
tuple<ll, ll, ll> eGCD(ll a, ll b) { return mut_div(a, b, 0, false); }

pair<ll, ll> crt_sub(ll a1, ll x1, ll a2, ll x2) {
  // DLOGKL("crt_sub", a1, x1, a2, x2);
  a1 = a1 % x1;
  a2 = a2 % x2;
  auto [g, s, t] = mut_div(x1, -x2, a2 - a1);
  // DLOGK(g, s, t);
  if (g == -1) return {-1, -1};
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

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      throw runtime_error("Fp::inv(): called for zero.");
    }
    auto [g, u, v] = eGCD(val, MOD);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
bool operator ==(int x, const Fp& y) { return Fp(x) == y; }
bool operator !=(int x, const Fp& y) { return Fp(x) != y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
bool operator ==(ll x, const Fp& y) { return Fp(x) == y; }
bool operator !=(ll x, const Fp& y) { return Fp(x) != y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
bool operator ==(const Fp& x, int y) { return x == Fp(y); }
bool operator !=(const Fp& x, int y) { return x != Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }
bool operator ==(const Fp& x, ll y) { return x == Fp(y); }
bool operator !=(const Fp& x, ll y) { return x != Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

#if !defined(CONSTANT_MOD)
ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998'244'353;
// WARNING: You should not uncomment here.  Instead, write
//    OUT OF LIBRARY PASTE AREA, such as in main():
//                     Fp::MOD = 998'244'353;
//    or whatever.  Or more preferably, use CONSTANT_MOD.
#endif

// ---- end mod.cc

// ---- inserted library file debug.cc
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

// ---- inserted function f:power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv(1);
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

// ad-hoc power function
template<typename T, typename Op>
T ah_power(T a, ll b, const T& unit_t, Op op) {
  T two_pow = a;
  T ret = unit_t;
  while (b > 0) {
    if (b & 1LL) ret = op(ret, two_pow);
    two_pow = op(two_pow, two_pow);
    b >>= 1;
  }
  return ret;
}
// ---- end f:power

// ---- inserted library file convolution.cc

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

#if defined(CONSTANT_MOD)
template <int m>
constexpr int ac_primitive_root = ac_primitive_root_constexpr(m);
constexpr int cv_get_mod() { return CONSTANT_MOD; }
constexpr int cv_get_primitive_root() {
  return ac_primitive_root<CONSTANT_MOD>;
}
#else
int cv_get_mod() { return Fp::MOD; }
int cv_get_primitive_root() { return ac_primitive_root_constexpr(Fp::MOD); }
#endif

void butterfly(vector<Fp>& a) {
  int g = cv_get_primitive_root();
  int n = int(a.size());
  int h = ac_ceil_pow2(n);

  DLOGK_LIB(g);

  static bool first = true;
  static Fp sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
  if (first) {
#if defined(CONSTANT_MOD)
    first = false;
#endif    
    Fp es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    int cnt2 = __builtin_ctz(cv_get_mod() - 1);
    Fp e = power<Fp>(Fp(g), (cv_get_mod() - 1) >> cnt2), ie = e.inv();
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
  DLOGK_LIB(cv_get_mod());
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

void butterfly_inv(vector<Fp>& a) {
  int g = cv_get_primitive_root();
  int n = int(a.size());
  int h = ac_ceil_pow2(n);

  static bool first = true;
  static Fp sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
  if (first) {
#if defined(CONSTANT_MOD)
    first = false;
#endif    
    Fp es[30], ies[30];  // es[i]^(2^(2+i)) == 1
    int cnt2 = __builtin_ctz(cv_get_mod() - 1);
    Fp e = power<Fp>(Fp(g), (cv_get_mod() - 1) >> cnt2), ie = e.inv();
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
          (long long)(cv_get_mod() + l.val - r.val) * inow.val;
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

vector<Fp> convolution(vector<Fp> a, vector<Fp> b) {
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

template<class T> // T must be integral.
vector<T> sub_convolution(int mod, const vector<T>& a, const vector<T>& b) {

#ifdef CONSTANT_MOD
  throw runtime_error("sub_convolution and convolution_ll cannot be called with CONSTANT_MOD defined");
#else

  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  int orig_mod = Fp::MOD;
  Fp::MOD = mod;
  vector<Fp> a2(n), b2(m);
  for (int i = 0; i < n; i++) { a2[i] = Fp(a[i]); }
  for (int i = 0; i < m; i++) { b2[i] = Fp(b[i]); }
  DLOGK_LIB(a2);
  DLOGK_LIB(b2);
  auto c2 = convolution(move(a2), move(b2));
  DLOGK_LIB(c2);
  vector<T> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) { c[i] = c2[i].val; }
  Fp::MOD = orig_mod;
  return c;

#endif
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

  auto c1 = sub_convolution(MOD1, a, b);
  auto c2 = sub_convolution(MOD2, a, b);
  auto c3 = sub_convolution(MOD3, a, b);
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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

// ---- inserted library file polynomial.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

template<typename T>
vector<T> polyConvolution(const vector<T>& a, const vector<T>& b) {
  assert(0);
}

template<>
vector<Fp> polyConvolution(const vector<Fp>& a, const vector<Fp>& b) {
  vector<Fp> aa(a);
  vector<Fp> bb(b);
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
  vector<T> coef;

  int degree() const { return coef.size() - 1; }

  Polynomial() : coef({(T)0}) {}
  Polynomial(T t) : coef({t}) {}

  Polynomial(const vector<T>& coef_) : coef(coef_) { adj_degree(); }
  Polynomial(vector<T>&& coef_) : coef(move(coef_)) { adj_degree(); }

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
    coef.resize(1);
    coef[0] = t;
    return *this;
  }

  void adj_degree() {
    while (coef.size() > 1 && coef.back() == (T)0) coef.pop_back();
  }

  Polynomial& operator +=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] += o.coef[i]; }
    adj_degree();
    return *this;
  }

  Polynomial& operator -=(const Polynomial& o) {
    int deg = max(degree(), o.degree());
    if ((int)coef.size() < deg + 1) { coef.resize(deg + 1); }
    for (int i = 0; i <= o.degree(); i++) { coef[i] -= o.coef[i]; }
    adj_degree();
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
    return *this;
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
  Polynomial operator -() const {
    return Polynomial() -= *this;
  }

  bool operator ==(const Polynomial& o) const { return coef == o.coef; }
  bool operator !=(const Polynomial& o) const { return coef != o.coef; }

  static Polynomial get_X() {
    return Polynomial({(T)0, (T)1});
  }

  T atval(T t) const {
    T ret = 0;
    for (ll i = coef.size() - 1; i >= 0; i--) { ret = ret * t + coef[i]; }
    return ret;
  }

  T selfDivideLinear(T c) {
    if (degree() == 0) {
      T m = coef[0];
      coef[0] = (T)0;
      return m;
    }
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

  // vec = p.divFormalSeries(q, n)
  //    vec[i] is the [x^i](p/q)  (formal power series) 
  //    vec.size() == n + 1
  // q.coef[0] should be (T)1
  vector<T> divFormalSeries(const Polynomial& q, int n) const {
    if (q.coef[0] != (T)1) {
      runtime_error("divFormalSeries: q.coef[0] should be (T)1.");
    }
    vector<T> ret(n + 1);
    int p_deg = degree();
    int q_deg = q.degree();
    for (int i = 0; i <= n; i++) {
      T s = i <= p_deg ? coef[i] : (T)0;
      for (int k = 1; k <= min(i, q_deg); k++) {
        s -= ret[i - k] * q.coef[k];
      }
      ret[i] = s;
    }
    return ret;
  }

  friend T bostanMori(const Polynomial& p, const Polynomial& q, ll n) {
    return p.subBostanMori(q, n);
  }
};

template<typename T, int use_fft>
Polynomial<T, use_fft> operator +(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) + p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator -(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) - p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator *(T t, const Polynomial<T, use_fft>& p) {
  return Polynomial<T, use_fft>(t) * p;
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator +(const Polynomial<T, use_fft>& p, T t) {
  return p + Polynomial<T, use_fft>(t);
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator -(const Polynomial<T, use_fft>& p, T t) {
  return p - Polynomial<T, use_fft>(t);
}
template<typename T, int use_fft>
Polynomial<T, use_fft> operator *(const Polynomial<T, use_fft>& p, T t) {
  return p * Polynomial<T, use_fft>(t);
}

template<typename T, int use_fft>
ostream& operator<< (ostream& os, const Polynomial<T, use_fft>& p) {
  os << p.coef;
  return os;
}

using PolyLL = Polynomial<ll, 2>;
using PolyFp = Polynomial<Fp, 1>;

// ---- end polynomial.cc

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
    assert(p1.coef[0] == -2 && p1.coef[1] == 0 && p1.coef[2] == 1);

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

    auto X = PolyLL::get_X();
    assert((X - 1LL) * (X - 1LL) == (X * X) - 2LL * X + 1LL);

    Fp::MOD = 2;
    auto Y = Polynomial<Fp, 0>::get_X();
    assert((Y - Fp(1)) * (Y - Fp(1)) == (Y * Y) + Fp(1));

  }
  cerr << "1 " << get_time_sec() - et << endl;
  et = get_time_sec();
  {
    Fp::MOD = 1e9 + 7;
    using Pol = Polynomial<Fp, 0>;
    Pol p1;
    assert(p1.degree() == 0 && p1.coef[0] == Fp(0));
    Pol p2(Fp(10));
    assert(p2.degree() == 0 && p2.coef[0] == Fp(10));
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

  const int primeB = 998'244'353;

  {
    Fp::MOD = primeB;
    using TupF = tuple<vector<Fp>, vector<Fp>, vector<Fp>>;
    vector<TupF> tests1({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {0}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {2,1}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,3},       {9},              {-2}},
        {{-1,3},      {9},              {0}},
        {{-1,3},      {0},              {3}},
        {{-1,-7},     {0},              {0}},
        {{3},         {4,3,2,1},        {0}}
      });
    for (auto [vq, vd, vm] : tests1) {
      PolyFp q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      DLOGK(p, q, d, m, dd, mm);
      assert(d == dd && m == mm);
      if (q.degree() == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.coef[0] / q.coef[1]);
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == q.coef[1] * d && PolyFp(mmm) == m);
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
        {{-3,1},      {9},              {0}},
        {{-8,1},      {0},              {3}},
        {{5,1},     {0},              {0}},
      });
    for (auto [vq, vd, vm] : tests2) {
      PolyLL q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
      if (q.degree() == 1 && q.coef[1] == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.coef[0]);
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
    Fp::MOD = primeB;
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
      assert(pol3X.coef[i] == pol3Y.coef[i]);
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
      assert(pol3X.coef[i] == pol3Y.coef[i]);
    }
  }
  cerr << "5 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Pol = PolyLL;
    Pol X = Pol::get_X();
    Pol p1 = Pol(1), p2 = Pol(1) - X;
    vector<ll> vec = p1.divFormalSeries(p2, 70);
    for (ll i = 0; i <= 70; i++) {
      assert(vec[i] == 1);
      assert(bostanMori(p1, p2, 1) == 1);
    }
  }
  cerr << "6 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    Fp::MOD = primeB;
    using Pol = PolyFp;
    Pol X = Pol::get_X();
    Pol p1 = Pol(1), p2 = Pol(1) - X - X*X;
    assert(bostanMori(p1, p2, 0) == Fp(1));
    assert(bostanMori(p1, p2, 1) == Fp(1));
    assert(bostanMori(p1, p2, 2) == Fp(2));
    assert(bostanMori(p1, p2, 10) == 89);
    vector<Fp> vec = p1.divFormalSeries(p2, 10);
    assert(vec == vector<Fp>({1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}));

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
      vector<Fp> vecR = p.divFormalSeries(q, degR);
      assert(vecR[degR] == bostanMori(p, q, degR));
      for (ll i = 0; i < 10; i++) {
        ll idx = randrange(0, degR);
        assert(vecR[idx] == bostanMori(p, q, idx));
      }
    }
  }
  cerr << "7 " << get_time_sec() - et << endl;
  et = get_time_sec();

  cout << "test done." << endl;

  return 0;
}

