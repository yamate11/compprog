#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(LinTr mod f:power)
// --> LinTr f:gcd mod f:power
// ---- inserted library file LinTr.cc

template <typename T>
struct LinTr {
  T p;
  T q;

  LinTr(int i) : p(i), q(0) {}
  LinTr(const LinTr& lt) : p(lt.p), q(lt.q) {}
  LinTr(T _p, T _q) : p(_p), q(_q) {}

  LinTr& operator *=(const LinTr& g) {
    q = p * g.q + q;
    p *= g.p;
    return *this;
  }

  bool operator ==(const LinTr& g) const { return p == g.p && q == g.q; }
  bool operator !=(const LinTr& g) const { return p != g.p || q != g.q; }

  LinTr operator *(const LinTr& g) const { return LinTr(*this) *= g; }

  T operator ()(T x) const { return p * x + q; }

};

template <typename T>
ostream& operator<<(ostream& os, const LinTr<T>& f) {
  return os << "{" << f.p << "x+" << f.q << "}";
}

// ---- end LinTr.cc
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
constexpr ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

constexpr ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(a, b, dummy1, dummy2);
}
// ---- end gcd
// ---- inserted library file mod.cc

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

struct Fp {
  ll val;

  Fp(ll t = 0) :
    val(t < 0 ? MOD + t % MOD : t >= MOD ? t % MOD : t) {}

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
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
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

// ---- end mod.cc
// ---- inserted function power from util.cc
/* *** WARNING ***  
      ll x = power(10, 12) 
   does not work since it is interpreted as 
      ll x = power<int>((int)10, 12)
   Use power<ll>(10, 12) or power(10LL, 12).
 */
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv = 1;
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
// ---- end power
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), L(N), C(N), p(N);
  for (ll i = 0; i < N; i++) {
    ll a, l; cin >> a >> l;
    ll c = 1, cc = 10;
    for ( ; a >= cc; c++, cc *= 10);
    A.at(i) = a; C.at(i) = c; L.at(i) = l;
  }
  ll B; cin >> B;
  if (B == 1) {
    cout << 0 << endl;
    return 0;
  }
  MOD = B;

  p.at(N-1) = 0;
  for (ll i = N-2; i >= 0; i--) {
    p.at(i) = p.at(i+1) + C.at(i+1) * L.at(i+1);
  }
  vector<Fp> x(N);
  for (ll i = 0; i < N; i++) {
    LinTr<Fp> f(power(Fp(10), C.at(i)), Fp(A.at(i)));
    x.at(i) = power(f, L.at(i))(0);
  }
  Fp t(0);
  for (ll i = 0; i < N; i++) {
    t += x.at(i) * power(Fp(10), p.at(i));
  }
  cout << (ll)t << endl;

  

  return 0;
}

