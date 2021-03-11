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

ll N;
vector<vector <ll>> nbr;

void farthest(ll ref, ll here, ll& node, ll& dist) {
  DLOG("farthest %lld %lld\n", ref, here);
  ll cmax = -1;
  ll cmaxarg;
  for (ll c : nbr.at(here)) {
    if (c == ref)  continue;
    ll nd;
    ll dt;
    farthest(here, c, nd, dt);
    if (cmax < dt) {
      cmax = dt;
      cmaxarg = nd;
    }
  }
  if (cmax == -1) {
    node = here;
    dist = 0;
  }else {
    node = cmaxarg;
    dist = cmax + 1;
  }
  DLOG("farthest %lld %lld ---> %lld %lld\n", ref, here, node, dist);
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  nbr.resize(N+1);
  for (ll i = 0; i < N-1; i++) {
    ll a, b;
    cin >> a >> b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  ll x, y, dist1, dist2;
  farthest(-1, 1, x, dist1);
  farthest(-1, x, y, dist2);
  DLOG("distance %lld\n", dist2);
  if ((dist2 + 2) % 3 == 0) {
    cout << "Second" << endl;
  }else {
    cout << "First" << endl;
  }

  return 0;
}

