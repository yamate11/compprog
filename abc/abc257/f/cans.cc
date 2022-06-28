#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const ll big = 1e16;
  ll N, M; cin >> N >> M;
  vector nbr(N, vector<ll>());
  vector<ll> und;
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    if (u == -1) {
      und.push_back(v);
    }else {
      nbr[u].push_back(v);
      nbr[v].push_back(u);
    }
  }
  auto dijk = [&](ll start) -> vector<ll> {
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] < d) continue;
      for (ll c : nbr[nd]) {
        ll newD = d + 1;
        if (newD >= dist[c]) continue;
        dist[c] = newD;
        pque.emplace(newD, c);
      }
    }
    return dist;
  };

  auto distA = dijk(0);
  auto distB = dijk(N - 1);
  if (und.empty()) {
    ll dd = distA[N - 1];
    if (dd >= big) dd = -1;
    REP(i, N) cout << dd << " ";
    cout << endl;
    return 0;
  }
  ll minA = big;
  ll minB = big;
  for (ll u : und) {
    updMin(minA, distA[u]);
    updMin(minB, distB[u]);
  }
  REP(i, N) {
    ll vmin = distA[N - 1];
    updMin(vmin, minA + 2 + minB);
    updMin(vmin, minA + 1 + distB[i]);
    updMin(vmin, distA[i] + 1 + minB);
    if (vmin >= big) cout << -1 << " ";
    else cout << vmin << " ";
  }
  cout << endl;

  return 0;
}

