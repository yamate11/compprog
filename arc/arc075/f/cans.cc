///////////////////////////////////////////////////////////////////////////////
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

bool sortf(ll x, ll y) { return pt.at(x) < pt.at(y); }

int main() {
  ll nN;
  cin >> nN;
  vector<ll> dD(nN);
  for (ll i = 0; i < nN; i++)  cin >> dD.at(i);
  vector<ll> pt(nN);
  for (ll i = 0; i < nN; i++)  pt(i) = i;
  sort(pt.begin(), pt.end(), [dD](x,y) { return dD.at(x) < dD.at(y); });
  
  return 0;
}

