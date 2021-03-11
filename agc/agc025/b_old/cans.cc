#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll MOD = 998244353;

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


struct Fp {
  ll val;

  Fp(ll t = 0) :
    val(t < 0 ? MOD + t % MOD : t >= MOD ? t % MOD : t) {}

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val > MOD) val -= MOD;
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

ll N, A, B, K;
vector<Fp> fact;
vector<Fp> invFact;

Fp combi(ll n, ll r) {
  Fp c = fact.at(n) * invFact.at(r) * invFact.at(n-r);
  DLOG("combi(%lld, %lld) = %lld\n", (ll)n, (ll)r, (ll)c);
  return c;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> A >> B >> K;
  ll p = 0;
  ll q = 0;
  ll g = eGCD(A, B, p, q);
  if (K % g != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll c = K / g;
  if (p <= 0) {
    swap(A, B);
    swap(p, q);
  }

  fact.resize(N+1);
  fact.at(0) = 1;
  for (int i = 1; i <= N; i++) {
    fact.at(i) = fact.at(i-1) * Fp(i);
  }
  invFact.resize(N+1);
  invFact.at(N) = fact.at(N).inv();
  for (int i = N; i >= 1; i--) {
    invFact.at(i-1) = invFact.at(i) * Fp(i);
  }
  // Apc + Bqc = K, p > 0, q <= 0
  // A(pc-Bt) + B(qc+At) = K, t \in [ (A - 1 - qc) / A, pc / B ]
  Fp cnt = 0;
  ll uA = A / g;
  ll uB = B / g;
  ll t0 = (uA-1 - q*c) / uA;
  ll tE = p*c / uB;
  ll nA = p*c - uB*(t0-1);
  ll nB = q*c + uA*(t0-1);
  for (ll t = t0; t <= tE; t++) {
    nA -= uB;
    nB += uA;
    DLOG("nA, nB = %lld, %lld\n", nA, nB);
    if (nA > N || nB > N) continue;
    cnt += combi(N, nA) * combi(N, nB);
  }
  cout << cnt << endl;


  return 0;
}

