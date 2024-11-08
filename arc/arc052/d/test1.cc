#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod)
// --> f:gcd mod
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

  Fp(ll t = 0) {
    if      (t >= MOD)  val = t % MOD;
    else if (t >= 0)    val = t;
    else if (t >= -MOD) val = t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) val = 0;
      else        val = v + MOD;
    }
  }

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
// @@ !! LIM  -- end mark --

ll func1(ll x) { return x % MOD; }
ll func2(ll x) { return x < MOD ? x : x % MOD; }
ll func3(ll x) {
  if (x >= MOD) return x % MOD;
  if (x >= 0) return x;
  ll v = x % MOD;
  if (v == 0) return 0;
  return v + MOD;
}
ll func4(ll x) {
  ll v = x % MOD;
  return v < 0 ? v + MOD : v;
}
ll func5(ll x) {
  return x >= MOD ? x % MOD : x >= 0 ? x : x % MOD == 0 ? 0 : x % MOD + MOD;
}

int main() {
  MOD = (ll)1e9 + 7;
  // MOD = 7;

  ll s1 = 0;
  ll s2 = 0;
  ll lim = (ll)1e6;
  auto start1 = chrono::system_clock::now();
  for (ll i = -lim; i < lim; i++) s1 += func3(i);
  auto start2 = chrono::system_clock::now();
  for (ll i = -lim; i < lim; i++) s2 += func4(i);
  auto start3 = chrono::system_clock::now();
  assert(s1 == s2);
  
  cout << (start2 - start1).count() << endl;
  cout << (start3 - start2).count() << endl;

  cout << ll(Fp(-1)) << endl;
}
