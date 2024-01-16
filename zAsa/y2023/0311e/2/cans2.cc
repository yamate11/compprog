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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpNbrList(N, N -1, nbr, dec=1) [GmyPILHg]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N -1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [GmyPILHg]
  if (N == 2) {
    cout << "Second\n";
    return 0;
  }
  ll root = 0;
  for (; SIZE(nbr[root]) == 1; root++);
  enum RC {None, Leaf, Other};
  auto dfs = [&](auto rF, ll nd, ll pt) -> RC {
    if (SIZE(nbr[nd]) == 1) return Leaf;
    ll numO = 0, numL = 0;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      RC rc = rF(rF, cld, nd);
      if (rc == Other) numO++;
      else if (rc == Leaf) numL++;
    }
    if (numL == 0 and numO == 0) return Leaf;
    else if (numL == 1 and numO == 0) return None;
    return Other;
  };

  RC rc = dfs(dfs, root, -1);
  if (rc == None) {
    cout << "Second\n";
  }else {
    cout << "First\n";
  }


  return 0;
}

