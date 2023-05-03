#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(convolution)

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

// @@ !! LIM -- end mark --
#line 7 "convolution_skel.cc"

template<typename T>
vector<T> naive_convolution(const vector<T>& x, const vector<T>& y) {
  ll nx = x.size();
  ll ny = y.size();
  vector<T> z(nx + ny - 1);
  for (ll i = 0; i < nx; i++) {
    for (ll j = 0; j < ny; j++) {
      z[i + j] += x[i] * y[j];
    }
  }
  return z;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist1(61, 130);
  uniform_int_distribution<int> dist2(-10000, 10000);
  uniform_int_distribution<int> dist3(0, 998'244'353 - 1);

  {
    using Fp = FpB;
    vector<Fp> vecA({1, 2, 3, 4});
    vector<Fp> vecB({-1, 0, 1, 2});
    auto res1 = convolution(vecA, vecB);
    auto res2 = naive_convolution(vecA, vecB);
    if (res1 != res2) {
      DLOGK_LIB(res1);
      DLOGK_LIB(res2);
      assert(res1 == res2);
    }
  }

  {
    using Fp = FpB;
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      vector<Fp> vecA;
      vector<Fp> vecB;
      for (ll j = 0; j < sza; j++) vecA.push_back(dist3(rng));
      for (ll j = 0; j < szb; j++) vecB.push_back(dist3(rng));
      auto res1 = convolution(vecA, vecB);
      auto res2 = naive_convolution(vecA, vecB);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }

  {
    using Fp = FpG<0>;
    Fp::setMod(primeB);
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      vector<Fp> vecA;
      vector<Fp> vecB;
      for (ll j = 0; j < sza; j++) vecA.push_back(dist3(rng));
      for (ll j = 0; j < szb; j++) vecB.push_back(dist3(rng));
      auto res1 = convolution(vecA, vecB);
      auto res2 = naive_convolution(vecA, vecB);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }

  if (1){
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      sza = 64;
      szb = 64;
      vector<ll> vec1;
      vector<ll> vec2;
      for (ll j = 0; j < sza; j++) vec1.push_back(dist2(rng));
      for (ll j = 0; j < szb; j++) vec2.push_back(dist2(rng));
      auto res1 = convolution_ll(vec1, vec2);
      auto res2 = naive_convolution(vec1, vec2);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }

  cout << "ok" << endl;
  return 0;
}
  
