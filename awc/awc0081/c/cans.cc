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
// published at https://github.com/yamate11/compprog-clib/blob/master/input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, S; cin >> N >> M >> S; S--;
  // @InpNbrList(N, M, fwd, dec=1, dir=True) [7OfgEEwd]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [7OfgEEwd]

  ll big = 1LL << 60;
  vector dist(N, big);
  queue<ll> que;
  dist[S] = 0;
  que.push(S);
  while (not que.empty()) {
    auto nd = que.front(); que.pop();
    for (ll peer : fwd[nd]) {
      if (dist[peer] == big) {
        dist[peer] = dist[nd] + 1;
        que.push(peer);
      }
    }
  }
  ll ans = *ranges::max_element(dist);
  if (ans == big) ans = -1;
  cout << ans << endl;
  return 0;
}

