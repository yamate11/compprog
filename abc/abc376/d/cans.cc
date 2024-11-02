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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> totop;
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
    if (v == 0) totop.push_back(u);
  }

  ll big = 1e18;
  vector dist(N, big);
  queue<ll> que;
  dist[0] = 0;
  que.push(0);
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll p : fwd[nd]) {
      if (dist[p] == big) {
        dist[p] = dist[nd] + 1;
        que.push(p);
      }
    }
  }
  ll ans = big;
  for (ll p : totop) {
    if (dist[p] < big) ans = min(ans, dist[p] + 1);
  }
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

