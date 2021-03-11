#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll mPrime = 1000*1000*1000 + 7;

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

int main() {
  ll a, b;
  cin >> a >> b;
  ll s, t;
  ll g = eGCD(a, b, s, t);
  printf("g=%lld, s=%lld, t=%lld\n", g, s, t);

  vector<ll> ts = {10, 250, 3, 498, 134142};
  for (ll x : ts) {
    cout << mMul(x, mInv(x)) << endl;
  }
    
}
  
