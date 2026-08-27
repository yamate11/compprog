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

  ll N, M; cin >> N >> M;
  vector nbr(N, vector<ll>());
  REP(i, 0, M) {
    ll u, v, s; cin >> u >> v >> s; u--; v--;
    if (s == 1) {
      nbr[u].push_back(v);
      nbr[v].push_back(u);
    }
  }
  ll big = 1LL << 60;
  vector<ll> dist(N, big);
  queue<ll> que;
  dist[0] = 0;
  que.push(0);
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll peer : nbr[nd]) {
      if (dist[peer] == big) {
        dist[peer] = dist[nd] + 1;
        que.push(peer);
      }
    }
  }
  ll ans = dist[N - 1];
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

