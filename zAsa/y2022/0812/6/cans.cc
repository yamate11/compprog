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

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector fwd(N, vector<ll>());
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    fwd[u].push_back(v);
  }
  ll S, T; cin >> S >> T; S--; T--;
  ll big = 1e9;
  vector dist(3, vector(N, big));
  dist[0][S] = 0;
  queue<pll> que;
  que.emplace(0, S);
  while (not que.empty()) {
    auto [layer, nd] = que.front(); que.pop();
    ll newL = (layer + 1) % 3;
    ll newD = dist[layer][nd] + 1;
    for (ll f : fwd[nd]) {
      if (newD < dist[newL][f]) {
        dist[newL][f] = newD;
        que.emplace(newL, f);
      }
    }
  }
  ll d = dist[0][T];
  cout << (d >= big ? -1 : d / 3) << endl;

  return 0;
}

