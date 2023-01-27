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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 1e6;

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [UDDR6NxQ]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [UDDR6NxQ]

  set<ll> ss;
  ll cnt = 0;
  auto dfs = [&](auto rF, ll nd) -> void {
    if (ss.find(nd) != ss.end()) return;
    ss.insert(nd);
    cnt++;
    if (cnt >= lim) throw myexc();
    for (ll cld : nbr[nd]) rF(rF, cld);
    ss.erase(nd);
  };
  try {
    dfs(dfs, 0);
    cout << cnt << endl;
    return 0;
  }catch(myexc& e) {
    cout << lim << endl;
    return 0;
  }
  return 0;
}

