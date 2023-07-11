#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpNbrList(N, M, nbr, dir=True, dec=1) [zQJ2SkjD]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
  }
  // @End [zQJ2SkjD]
  ll S, T; cin >> S >> T; S--; T--;
  queue<pll> que;
  const ll big = 1e18;
  vector dist(3, vector<ll>(N, big));
  dist[0][S] = 0;
  que.emplace(0, S);
  while (not que.empty()) {
    auto [lev, nd] = que.front(); que.pop();
    ll newLev = (lev + 1) % 3;
    ll newDist = dist[lev][nd] + 1;
    for (ll peer : nbr[nd]) {
      if (dist[newLev][peer] == big) {
        dist[newLev][peer] = newDist;
        que.emplace(newLev, peer);
      }
    }
  }
  ll ans = dist[0][T];
  if (ans == big) ans = -1;
  else ans /= 3;
  cout << ans << endl;

  return 0;
}

