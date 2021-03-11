#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod)
// --> f:gcd mod
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
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

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// ---- inserted library file mod.cc

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

struct Fp {
  ll val;

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

  Fp(ll t = 0) : val(_calc_from_ll(t)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = _calc_from_ll(t); return *this; }
  Fp& operator =(int t) { val = _calc_from_ll(t); return *this; }

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

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

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

// ---- end mod.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  MOD = K;
  ll cnt = 1;
  Fp num = Fp(7);
  for (ll i = 0; i < K+10; i++) {
    if (num == Fp(0)) {
      cout << cnt << endl;
      return 0;
    }
    num = num * 10 + 7;
    cnt++;
  }
  cout << "-1" << endl;


  return 0;
}

