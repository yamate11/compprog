#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll mPrime = 998244353;

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



ll N;
vector<ll> A;
vector<ll> dp;
vector<ll> dp2;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  A.resize(N);
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  ll half = (sum + 1) / 2;
  dp.resize(half+1);
  dp.at(0) = 1;
  for (ll i = 0; i < N; i++) {
    dp.at(half) = mMul(3, dp.at(half));
    for (ll k = half - 1; k >= 0; k--) {
      ll j = min(k + A.at(i), half);
      dp.at(j) = mAdd(dp.at(j), dp.at(k));
      dp.at(k) = mMul(2, dp.at(k));
    }
  }
  ll bad1 = dp.at(half);
  dp2.resize(half+1);
  dp2.at(0) = 1;
  for (ll i = 0; i < N; i++) {
    for (ll k = half - 1; k >= 0; k--) {
      ll j = k + A.at(i);
      if (j > half)  continue;
      dp2.at(j) = mAdd(dp2.at(j), dp2.at(k));
    }
  }
  ll bad2;
  if (sum % 2 == 0) {
    bad2 = dp2.at(half);
  }else {
    bad2 = 0;
  }
  ll bad = mSub(mMul(3, bad1), mMul(3, bad2));
  ll all = 1;
  for (ll i = 0; i < N; i++)  all = mMul(3, all);
  ll good = mSub(all, bad);
  DLOG("bad1 = %lld, bad2 = %lld, all = %lld, good = %lld\n", bad1, bad2, all, good);
  cout << good << endl;

  return 0;
}

