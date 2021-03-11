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

ll mPrime = int(1e9) + 7;

ll mAdd(ll x, ll y) {
  ll z = x + y;
  if (z < mPrime)  return z;
  else             return (z - mPrime);
}

ll mSub(ll x, ll y) {
  ll z = x - y;
  if (z >= 0)  return z;
  else         return (z + mPrime);
}

ll mMul(ll x, ll y) {
  return (x * y) % mPrime;
}

ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

ll mInv(ll x) {
  ll s, t;
  eGCD(x, mPrime, s, t);
  return s < 0 ? s + mPrime : s;
}

// Combination.  This is only for one-shot.
ll combi(ll n, ll r) {
  if (n-r < r) { return combi(n, n-r); }
  ll x = 1;
  ll y = 1;
  for (ll i = 0; i < r; i++) {
    x = mMul(x, n-i);
    y = mMul(y, r-i);
  }
  return mMul(x, mInv(y));
}

ll N, M, K;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M >> K;

  ll s1 = 0;
  for (ll n = 1; n <= N-1; n++) {
    s1 = mAdd(s1, mMul(n, (N - n)));
  }
  s1 = mMul(s1, mMul(M, M));

  ll s2 = 0;
  for (ll m = 1; m <= M-1; m++) {
    s2 = mAdd(s2, mMul(m, M - m));
  }
  s2 = mMul(s2, mMul(N, N));

  ll s = mAdd(s1, s2);
  ll answer = mMul(s, combi(N*M - 2, K-2));
  cout << answer << endl;

  return 0;
}

