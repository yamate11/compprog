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

ll N, X;
vector<ll> fib;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> X;
  fib.resize(X);
  fib.at(0) = 1;
  fib.at(1) = 1;
  for (ll i = 2; i < X; i++) {
    fib.at(i) = mAdd(fib.at(i-2), fib.at(i-1));
  }
  

  return 0;
}

