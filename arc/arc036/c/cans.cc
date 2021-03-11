#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- MOD begin --- cut here ---

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
 */
#if !DEFINED_POWER
template<typename T>
T power(T a, ll b) {
  cerr << "Warning: power(10, 10) does not work.  power<ll>(10, 10) or power(10LL, 10) is OK.  Remove this line once confirmed.\n";
  T twoPow = a;
  T rv = 1;
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
#endif

// --- MOD end --- cut here ---


using Vec1 = vector<Fp>;
using Vec2 = vector<Vec1>;
using Vec3 = vector<Vec2>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  Vec3 dp(N+1, Vec2(K+1, Vec1(K+1)));
  dp.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j <= K; j++) {
      for (ll k = 0; k <= K; k++) {
	Fp x = dp.at(i).at(j).at(k);
	if (S.at(i) != '1' && j+1 <= K) {
	  ll kk = max(0LL, k-1);
	  dp.at(i+1).at(j+1).at(kk) += x;
	}
	if (S.at(i) != '0' && k+1 <= K) {
	  ll jj = max(0LL, j-1);
	  dp.at(i+1).at(jj).at(k+1) += x;
	}
      }
    }
  }
  Fp acc = 0;
  for (ll j = 0; j <= K; j++) {
    for (ll k = 0; k <= K; k++) acc += dp.at(N).at(j).at(k);
  }
  cout << acc << endl;

  return 0;
}

