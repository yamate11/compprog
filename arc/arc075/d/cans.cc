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

ll nN, aA, bB;
vector<ll> hH;

ll binsch(ll a, ll b, auto f) {
  while (a+1 < b) {
    ll m = (a + b) / 2;
    if (f(m))  b = m;
    else       a = m;
  }
  return b;
}

bool ftry(ll k) {
  ll sum = 0;
  for (ll i = 0; i < nN; i++) {
    ll m = hH.at(i) - k * bB;
    if (m <= 0)  continue;
    sum += (m + aA - bB - 1) / (aA - bB);
  }
  return sum <= k;
}

int main() {
  cin >> nN >> aA >> bB;
  hH.resize(nN);
  for (ll i = 0; i < nN; i++)  cin >> hH.at(i);
  ll ans = binsch(0, int(1e9), ftry);
  cout << ans << endl;
  
  return 0;
}

