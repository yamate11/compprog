#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod fastTransform)

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

// ---- inserted library file mod.cc

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
    if (val == 0) {
      throw runtime_error("FpG::inv(): called for zero.");
    }
    auto [g, u, v] = eGCD(val, getMod());
    return FpG(u);
  }

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

template<int mod=0>
class CombG {
  int nMax;
  vector<FpG<mod>> vFact;
  vector<FpG<mod>> vInvFact;
public:
  CombG(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  FpG<mod> fact(int n) { return vFact.at(n); }
  FpG<mod> comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  FpG<mod> perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

constexpr int primeA = 1'000'000'007;
constexpr int primeB = 998'244'353;          // '
using FpA = FpG<primeA>;
using FpB = FpG<primeB>;
using CombA = CombG<primeA>;
using CombB = CombG<primeB>;

// ---- end mod.cc

// ---- inserted library file fastTransform.cc

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

template<typename T>
void zeta_upper(vector<T>& f) { _trans_form<T, 1, 1, 0, 1, 1>(f); }

template<typename T>
void moebius_upper(vector<T>& f) { _trans_form<T, 1, -1, 0, 1, 1>(f); }

template<typename T>
void zeta_lower(vector<T>& f) { _trans_form<T, 1, 0, 1, 1, 1>(f); }

template<typename T>
void moebius_lower(vector<T>& f) { _trans_form<T, 1, 0, -1, 1, 1>(f); }

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

// @@ !! LIM -- end mark --

ll op_xor(ll x, ll y) { return x ^ y; }
ll op_or(ll x, ll y) { return x | y; }
ll op_and(ll x, ll y) { return x & y; }

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

  {
    vector<ll> vec1 = {2, 3, 5};
    vector<ll> vec2 = {3, 1, -2};
    auto vec = xor_conv(vec1, vec2);
    assert (vec == vector<ll>({-1, 11, 11, -1}));
    vec = and_conv(vec1, vec2);
    assert (vec == vector<ll>({27, 3, -10, 0}));
    vec = or_conv(vec1, vec2);
    assert (vec == vector<ll>({6, 14, 1, -1}));
  }
  {
    using Fp = FpA;
    auto check = [&](const vector<Fp>& vec, const vector<Fp>& vec1,
                     const vector<Fp>& vec2, 
                     ll op(ll, ll)) -> void {
      ll t1 = vec1.size();
      ll t2 = vec2.size();
      vector<ll> ref;
      for (ll i = 0; i < t1; i++) {
        for (ll j = 0; j < t2; j++) {
          ll k = op(i, j);
          if (k >= (ll)ref.size()) ref.resize(k + 1);
          ref[k] += vec1[i] * vec2[j];
        }
      }
      assert(ref.size() <= vec.size());
      for (ll i = 0; i < (ll)ref.size(); i++) assert(ref[i] == vec[i]);
      for (ll i = ref.size(); i < (ll)vec.size(); i++) assert(vec[i] == 0);
    };

    ll smax = 40;
    for (ll _t = 0; _t < 1000; _t++) {
      ll t1 = randrange(1, smax + 1);
      ll t2 = randrange(1, smax + 1);
      vector<Fp> vec1(t1);
      vector<Fp> vec2(t2);
      for (ll i = 0; i < t1; i++) vec1[i] = randrange(0, primeA);
      for (ll i = 0; i < t2; i++) vec2[i] = randrange(0, primeA);
      check(xor_conv(vec1, vec2), vec1, vec2, op_xor);
      check(and_conv(vec1, vec2), vec1, vec2, op_and);
      check(or_conv(vec1, vec2), vec1, vec2, op_or);
    }
  }
  {
    using Fp = FpB;
    ll pmax = 5;
    for (ll _t = 0; _t < 1000; _t++) {
      ll t1 = randrange(1, pmax + 1);
      ll sz = 1 << t1;
      vector<Fp> vec1(sz);
      for (ll i = 0; i < sz; i++) vec1[i] = randrange(0, primeB);
      vector<Fp> tr(sz);
      for (ll x = 0; x < sz; x++) {
        for (ll y = 0; y < sz; y++) {
          if ((x | y) == y) { tr[x] += vec1[y]; }
        }
      }
      vector<Fp> tr2(vec1);
      zeta_upper(tr2);
      assert(tr == tr2);
      moebius_upper(tr2);
      assert(vec1 == tr2);

      vector<Fp> tr_low(sz);
      for (ll x = 0; x < sz; x++) {
        for (ll y = 0; y < sz; y++) {
          if ((x & y) == y) { tr_low[x] += vec1[y]; }
        }
      }
      zeta_lower(tr2);
      assert(tr_low == tr2);
      moebius_lower(tr2);
      assert(vec1 == tr2);
    }
  }


  return 0;
}

