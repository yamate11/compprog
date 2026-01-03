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

// @@ !! LIM(wavelet mod)

// ---- inserted library file wavelet.cc

struct BitVector {
  ll N;
  ll vsize;
  vector<int> vs;
  vector<u64> vb;
  bool built;
  BitVector() = default;
  BitVector(ll N_) : N(N_), vsize((N + 63) / 64), vs(vsize + 1), vb(vsize), built(false) {}
  void set(bool val, int k) {
    if (built) throw runtime_error("already built.");
    if (val) vb[k >> 6] |=   1ULL << (k & 63);
    else     vb[k >> 6] &= ~(1ULL << (k & 63));
  }
  bool at(ll k) { return static_cast<bool>(vb[k >> 6] >> (k & 63) & 1); }
  void build() {
    if (not built) {
      for (ll i = 0; i < vsize; i++) vs[i + 1] = vs[i] + popcount(vb[i]);
      built = true;
    }
  }
  ll rank(bool val, ll k) {
    if (not built) build();
    ll cnt1 = (k >= N) ? vs.back() : vs[k >> 6] + popcount(vb[k >> 6] & ((1ULL << (k & 63)) - 1));
    if (val) return cnt1;
    else     return k - cnt1;
  }

  // for debugging
  vector<bool> vec_view() {
    vector<bool> vec(N);
    for (ll i = 0; i < N; i++) vec[i] = at(i);
    return vec;
  }

};

template<typename INT=ll>
struct WaveletMatrix {
  ll N;
  ll ht;
  vector<BitVector> vbv;
  vector<int> mid;

  pair<bool, INT> _h_rest(ll h, INT t) { return {t >> h & 1, t & ((static_cast<INT>(1) << h) - 1)}; }

  WaveletMatrix() = default;
  WaveletMatrix(const auto& vec, ll amax) { _init(vec, amax); }
  void _init(const auto& vec, ll amax) {
    if (amax < 0) amax = vec.empty() ? 1 : *max_element(vec.begin(), vec.end());
    N = ssize(vec);
    ht = bit_width((u64)amax);
    vbv = vector(ht, BitVector(N));
    mid = vector<int>(ht);
    vector tmpA{vec, vector<INT>(N)};
    vector tmpB(2, vector<INT>(N));
    vector<ll> a{N, 0};
    vector<ll> b{0, 0};
    for (ll h = ht - 1; h >= 0; h--) {
      for (int e = 0; e < 2; e++) {
        for (ll i = 0; i < a[e]; i++) {
          auto [x, y] = _h_rest(h, tmpA[e][i]);
          vbv[h].set(x, e == 0 ? i : a[0] + i);
          tmpB[x][b[x]++] = y;
        }
      }
      mid[h] = b[0];
      swap(tmpA, tmpB);
      a = b;
      b[0] = b[1] = 0;
    }
  }
  
  pair<ll, ll> _next_range(bool x, ll l, ll r, ll h) {
    return {x * mid[h] + vbv[h].rank(x, l), x * mid[h] + vbv[h].rank(x, r)};
  }

  // vec[p]
  INT access(ll p) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      bool x = vbv[h].at(p);
      if (x == 1) ret |= INT(1) << h;
      if (x == 0) p =          vbv[h].rank(0, p);
      else        p = mid[h] + vbv[h].rank(1, p);
    }
    return ret;
  }

  // #{ i < r : vec[i] == t }
  ll rank(INT t, ll r) {
    if (bit_width((u64)t) > ht) return 0;
    ll l = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = t >> h & 1;
      tie (l, r) = _next_range(x, l, r, h);
    }
    return r - l;
  }

  // k-th smallest value in vec[l, r)   (0-indexed)
  INT kth_smallest(ll k, ll l, ll r) {
    if (k < 0 or k >= r - l) throw runtime_error("k out of range");
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll num0 = vbv[h].rank(0, r) - vbv[h].rank(0, l);
      bool x = k >= num0;
      if (x) {
        k -= num0;
        ret |= INT(1) << h;
      }
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // k-th largest value in vec[l, r)   (0-indexed)
  INT kth_largest(ll k, ll l, ll r) { return kth_smallest(r - l - 1 - k, l, r); }

  // #{ i \in [l, r) : vec[i] < hi }
  ll range_freq(INT hi, ll l, ll r) {
    if (bit_width((u64)hi) > ht) return r - l;
    ll ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = hi >> h & 1;
      if (x == 1) ret += vbv[h].rank(0, r) - vbv[h].rank(0, l);
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{i \in [l, r) : lo <= vec[i] < hi }
  ll range_freq(INT lo, INT hi, ll l, ll r) { return range_freq(hi, l, r) - range_freq(lo, l, r); }


};



// ---- end wavelet.cc

// ---- inserted library file algOp.cc

// Common definitions
//    zero, one, inverse

template<typename T>
const T zero(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)0; }
  else { return t.zero(); }
}

template<typename T>
const T one(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)1; }
  else { return t.one(); }
}

template<typename T>
const T inverse(const T& t) {
  if constexpr (is_floating_point_v<T>) { return 1.0 / t; }
  else { return t.inverse(); }
}

#ifdef BOOST_MP_CPP_INT_HPP
template<> const cpp_int zero(const cpp_int& t) { return cpp_int(0); }
template<> const cpp_int one(const cpp_int& t) { return cpp_int(1); }
#endif // BOOST_MP_CPP_INT_HPP

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
template<typename INT=ll>
tuple<INT, INT, INT> eGCD(INT a, INT b) {
  INT sa = a < 0 ? -1 : 1;
  INT ta = 0;
  INT za = a * sa;
  INT sb = 0;
  INT tb = b < 0 ? -1 : 1;
  INT zb = b * tb;
  while (zb != 0) {
    INT q = za / zb;
    INT r = za % zb;
    za = zb;
    zb = r;
    INT new_sb = sa - q * sb;
    sa = sb;
    sb = new_sb;
    INT new_tb = ta - q * tb;
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

template<int mod=0, typename INT=ll>
struct FpG {   // G for General
  static INT dyn_mod;

  static INT getMod() {
    if (mod == 0) return dyn_mod;
    else          return (INT)mod;
  }
  
  // Effective only when mod == 0.
  // _mod must be less than the half of the maximum value of INT.
  static void setMod(INT _mod) {  
    dyn_mod = _mod;
  }

  static INT _conv(INT x) {
    if (x >= getMod())  return x % getMod();
    if (x >= 0)         return x;
    if (x >= -getMod()) return x + getMod();
    INT y = x % getMod();
    if (y == 0) return 0;
    return y + getMod();
  }

  INT val;

  FpG(INT t = 0) : val(_conv(t)) {}
  FpG(const FpG& t) : val(t.val) {}
  FpG& operator =(const FpG& t) { val = t.val; return *this; }
  FpG& operator =(INT t) { val = _conv(t); return *this; }

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
  
  operator INT() const { return val; }

  friend FpG operator +(INT x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(INT x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(INT x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(INT x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(INT x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(INT x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, INT y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, INT y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, INT y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, INT y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, INT y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, INT y) { return x != FpG(y); }

  /* The following are needed to avoid warnings in cases such as FpG x; x = 5 + x; rather than x = FpG(5) + x; */
  friend FpG operator +(int x, const FpG& y) { return FpG(x) + y; }
  friend FpG operator -(int x, const FpG& y) { return FpG(x) - y; }
  friend FpG operator *(int x, const FpG& y) { return FpG(x) * y; }
  friend FpG operator /(int x, const FpG& y) { return FpG(x) / y; }
  friend bool operator ==(int x, const FpG& y) { return FpG(x) == y; }
  friend bool operator !=(int x, const FpG& y) { return FpG(x) != y; }
  friend FpG operator +(const FpG& x, int y) { return x + FpG(y); }
  friend FpG operator -(const FpG& x, int y) { return x - FpG(y); }
  friend FpG operator *(const FpG& x, int y) { return x * FpG(y); }
  friend FpG operator /(const FpG& x, int y) { return x / FpG(y); }
  friend bool operator ==(const FpG& x, int y) { return x == FpG(y); }
  friend bool operator !=(const FpG& x, int y) { return x != FpG(y); }

  friend istream& operator>> (istream& is, FpG& t) {
    INT x; is >> x;
    t = x;
    return is;
  }

  friend ostream& operator<< (ostream& os, const FpG& t) {
    os << t.val;
    return os;
  }

};
template<int mod, typename INT>
INT FpG<mod, INT>::dyn_mod;

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
using FpA = FpG<primeA, ll>;
using FpB = FpG<primeB, ll>;

// ---- end mod.cc

// @@ !! LIM -- end mark --

using Fp = FpB;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e18;

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [4zhl28iC]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [4zhl28iC]
  // @InpVec(M, B) [a9JWfzA9]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [a9JWfzA9]

  ll g = gcd(N, M);
  ll NN = N / g;
  ll MM = M / g;
  vector<ll> IA(NN);
  REP(i, 0, NN) IA[i] = (i * M) % N;
  vector<ll> IB(MM);
  REP(i, 0, MM) IB[i] = (i * N) % M;
  vector<ll> RA(N);
  REP(i, 0, NN) RA[IA[i]] = i;
  vector<ll> RB(M);
  REP(i, 0, MM) RB[IB[i]] = i;

  ll period = N * M / g;
  ll num_per = K / period;
  ll rem_per = K % period;

  Fp ans = 0;
  REP(q, 0, g) {
    vector<ll> V(2 * MM);
    REP(i, 0, MM) V[i] = V[MM + i] = B[q + IB[i]];
    WaveletMatrix wm(V, -1);
    REP(p, 0, NN) {
      ll i = p * g + q;
      ll ri = RB[(p % MM) * g];
      ll rem = rem_per / N;
      if (i < rem_per % N) rem++;
      ll x = wm.range_freq(A[i], big, ri, ri + MM);
      ll y = wm.range_freq(A[i], big, ri, ri + rem);
      ans += Fp(A[i]) * x * num_per + Fp(A[i]) * y;
    }
  }
  REP(q, 0, g) {
    vector<ll> V(2 * NN);
    REP(i, 0, NN) V[i] = V[NN + i] = A[q + IA[i]];
    WaveletMatrix wm(V, -1);
    REP(p, 0, MM) {
      ll i = p * g + q;
      ll ri = RA[(p % NN) * g];
      ll rem = rem_per / M;
      if (i < rem_per % M) rem++;
      ll x = wm.range_freq(B[i] + 1, big, ri, ri + NN);
      ll y = wm.range_freq(B[i] + 1, big, ri, ri + rem);
      ans += Fp(B[i]) * x * num_per + Fp(B[i]) * y;
    }
  }
  cout << ans << endl;

  return 0;
}

