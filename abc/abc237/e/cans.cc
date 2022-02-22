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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> H(N);
  REP(i, N) cin >> H[i];
  vector<vector<ll>> nbr(N);
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  pque.emplace(0, 0);
  ll big = 1e17;
  vector<ll> dist(N, big);
  dist[0] = 0;
  while (not pque.empty()) {
    auto [d, x] = pque.top(); pque.pop();
    if (dist[x] < d) continue;
    for (ll y : nbr[x]) {
      ll diff = max(0LL, H[y] - H[x]);
      ll newd = d + diff;
      if (dist[y] <= newd) continue;
      dist[y] = newd;
      pque.emplace(newd, y);
    }
  }
  REP(x, N) H[x] += dist[x];
  ll vmin = H[0];
  REP(x, N) vmin = min(vmin, H[x]);
  cout << H[0] - vmin << endl;

  return 0;
}

