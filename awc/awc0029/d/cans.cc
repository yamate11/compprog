#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  vector nbr(N, vector<ll>());
  REP(i, 0, M) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    if (w >= K) {
      nbr[u].push_back(v);
      nbr[v].push_back(u);
    }
  }
  ll big = 1e18;
  vector dist(N, big);
  queue<ll> que;
  dist[0] = 0;
  que.push(0);
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    if (nd == N - 1) {
      cout << dist[N - 1] << endl;
      return 0;
    }
    for (ll p : nbr[nd]) {
      if (dist[p] == big) {
        dist[p] = dist[nd] + 1;
        que.push(p);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

