#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// ----------------------------------------------------------------------

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

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

/* 
   Power function    power(a, b) == a^b
   Speed is O(log b).
   The same source code can be used for integers by replacing
   Fp with int etc.  Unfortunately, replacing Fp with auto does not
   make the function generic for int and Fp.
 */
Fp power(Fp a, int b) {
  Fp twoPow = a;
  Fp rv = 1;
  while (b > 0) {
    if (b & 1) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
// ----------------------------------------------------------------------

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  Fp cnt = 1;
  vector<int> nxt(3);
  nxt.at(0) = nxt.at(1) = nxt.at(2) = 0;
  for (int i = 0; i < N; i++) {
    int k = 0;
    int j0 = -1;
    for (int j = 0; j < 3; j++) {
      if (nxt.at(j) == A.at(i)) {
	k++;
	j0 = j;
      }
    }
    if (j0 < 0) {
      cout << 0 << endl;
      return 0;
    }
    cnt *= Fp(k);
    nxt.at(j0)++;
  }
  cout << (int)cnt << endl;

  return 0;
}

