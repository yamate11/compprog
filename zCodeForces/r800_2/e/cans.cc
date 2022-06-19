#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using pll = pair<ll, ll>;
  ll N, M; cin >> N >> M;
  vector bwd(N, vector<ll>());
  // vector fwd(N, vector<ll>());
  vector<map<ll, ll>> fmp(N);
  vector<ll> fcnt(N);
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    bwd[v].push_back(u);
    fcnt[u]++;
    fmp[u][v]++;
  }
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  const ll big = 1e18;
  vector<ll> dist(N, big);
  dist[N - 1] = 0;
  pque.emplace(0, N - 1);
  while (not pque.empty()) {
    auto [d, n] = pque.top(); pque.pop();
    if (dist[n] < d) continue;
    if (n == 0) {
      cout << d << endl;
      return 0;
    }
    // n is now fixed.
    for (ll m : bwd[n]) {
      fcnt[m] -= fmp[m][n];
      fmp[m].erase(n);
    }
    for (ll m : bwd[n]) {
      ll newD = d + fcnt[m] + 1;
      if (dist[m] <= newD) continue;
      dist[m] = newD;
      pque.emplace(newD, m);
    }
  }

  return 0;
}

