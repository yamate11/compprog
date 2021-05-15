#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/convolution>
// using namespace atcoder;

#ifdef USE_CONSTANT_MOD
#define CONSTANT_MOD 998244353
#endif

// @@ !! LIM(convolution f:perfmeas)

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
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

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

  Fp::MOD = 998'244'353;

  const ll lim = 1e4;
  vector<ll> vec1(lim), vec2(lim);
  for (ll i = 0; i < lim; i++) {
    vec1[i] = randrange(0, 1000);
    vec2[i] = randrange(0, 1000);
  }

  using ami = atcoder::modint998244353;

  vector<Fp> vecf1(lim), vecf2(lim);
  vector<ami> vecm1(lim), vecm2(lim);
  for (ll i = 0; i < lim; i++) {
    vecf1[i] = vec1[i];
    vecf2[i] = vec2[i];
    vecm1[i] = vec1[i];
    vecm2[i] = vec2[i];
  }

  Fp fs = 0;
  ami ms = 0;
  ll ls = 0;

  double et1 = get_time_sec();

  for (ll i = 0; i < lim; i++) {
    for (ll j = 0; j < lim; j++) {
      ms += vecm1[i] * vecm2[i];
    }
  }

  double et2 = get_time_sec();

  for (ll i = 0; i < lim; i++) {
    for (ll j = 0; j < lim; j++) {
      fs += vecf1[i] * vecf2[i];
    }
  }

  double et3 = get_time_sec();
  
  for (ll i = 0; i < lim; i++) {
    for (ll j = 0; j < lim; j++) {
      ls += vec1[i] * vec2[i];
    }
  }

  double et4 = get_time_sec();
  
  cout << "a " << et2 - et1 << endl;
  cout << "b " << et3 - et2 << endl;
  cout << "c " << et4 - et3 << endl;

  cout << fs << " " << ms.val() << endl;

  return 0;
}

