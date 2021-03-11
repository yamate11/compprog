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

ll big = 101;

int main() {
  ll bN;
  cin >> bN;
  vector<string> bS(bN);
  ll sum = 0;
  ll nonMult = big;
  for (ll i = 0; i < bN; i++)  {
    ll x;
    cin >> x;
    sum += x;
    if (x % 10 != 0 && x < nonMult)  nonMult = x;
  }
  ll ans = sum % 10 != 0 ? sum : nonMult == big ? 0 : sum - nonMult;
  cout << ans << endl;
  return 0;
}

