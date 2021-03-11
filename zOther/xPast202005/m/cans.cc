#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector nbr(N, vector<ll>());
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr.at(u).push_back(v);
    nbr.at(v).push_back(u);
  }
  ll start; cin >> start; start--;
  ll K; cin >> K;
  vector<ll> t(K);
  for (ll i = 0; i < K; i++) {
    ll z; cin >> z; z--;
    t.at(i) = z;
  }

  using Pair = pair<ll, ll>;
  vector<ll> sdist(K);
  vector<vector<ll>> dist(K, vector<ll>(K));
  for (ll k = 0; k < K; k++) {
    vector ds(N, -1LL);
    queue<Pair> que;
    que.emplace(t.at(k), 0);
    while (!que.empty()) {
      auto [i, d] = que.front(); que.pop();
      if (ds.at(i) >= 0) continue;
      ds.at(i) = d;
      for (ll j : nbr.at(i)) {
	if (ds.at(j) >= 0) continue;
	que.emplace(j, d + 1);
      }
    }
    sdist.at(k) = ds.at(start);
    for (ll m = 0; m < K; m++) {
      dist.at(k).at(m) = ds.at(t.at(m));
    }
  }

  ll full = 1LL << K;
  vector tbl(full, vector<ll>(K, LLONG_MAX));
  for (ll k = 0; k < K; k++) {
    tbl.at(1LL << k).at(k) = sdist.at(k);
  }
  for (ll x = 1; x < full; x++) {
    for (ll k = 0; k < K; k++) {
      if (!(x & (1LL << k))) continue;
      for (ll m = 0; m < K; m++) {
	if ((x & (1LL << m))) continue;
	assert(tbl.at(x).at(k) < LLONG_MAX);
	updMin(tbl.at(x | (1LL << m)).at(m),
	       tbl.at(x).at(k) + dist.at(k).at(m));
      }
    }
  }
  ll ans = LLONG_MAX;
  for (ll k = 0; k < K; k++) ans = min(ans, tbl.at(full - 1).at(k));
  cout << ans << endl;

  return 0;
}

