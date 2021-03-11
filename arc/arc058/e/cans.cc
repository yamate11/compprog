#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod f:power)
// --> f:gcd mod f:power
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

ll pos(ll p) { return 1LL << (p-1); }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  MOD = 1e9 + 7;

  ll N, X, Y, Z; cin >> N >> X >> Y >> Z;
  ll T = pos(X+Y+Z+1);
  ll full = T - 1;
  ll pat = pos(X+Y+Z) | pos(Y+Z) | pos(Z);
  vector<vector<Fp>> tbl(N+1, vector<Fp>(T));
  tbl.at(0).at(0) = 1;
  for (ll i = 0; i < N; i++) {
    for (ll x = 0; x < T; x++) {
      if ((x & pat) == pat) continue;
      for (ll d = 1; d <= 10; d++) {
	ll y = ((x << d) | pos(d)) & full;
	tbl.at(i+1).at(y) += tbl.at(i).at(x);
      }
    }
  }
  Fp tot = 0;
  for (ll x = 0; x < T; x++) if ((x & pat) != pat) tot += tbl.at(N).at(x);
  cout << (ll)(power(Fp(10), N) - tot) << endl;

  return 0;
}

