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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpNbrList(N, N-1, nbr, dec=1) [LUfQ2KxG]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N-1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [LUfQ2KxG]
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    cout << nd + 1 << " ";
    sort(ALL(nbr[nd]));
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      cout << nd + 1 << " ";
    }
  };
  dfs(dfs, 0, -1);
  cout << endl;

  return 0;
}

