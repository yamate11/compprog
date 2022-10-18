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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, Y; cin >> N >> X >> Y; X--; Y--;
  // @InpNbrList(N, N - 1, nbr, dec=1) [xDzM1b1A]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [xDzM1b1A]
  vector<ll> path;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    path.push_back(nd);
    if (nd == Y) {
      REPOUT(i, 0, SIZE(path), path[i] + 1, " ");
    }
    for (ll peer : nbr[nd]) {
      if (peer == pt) continue;
      rF(rF, peer, nd);
    }
    path.pop_back();
  };
  dfs(dfs, X, -1);


  return 0;
}

