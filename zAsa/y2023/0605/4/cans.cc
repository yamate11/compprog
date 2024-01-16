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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [1IrNL1gj]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [1IrNL1gj]

  ll lim = 1e6;
  ll cnt = 0;
  vector<bool> onStack(N);
  vector<ll> stack;
  auto dfs = [&](auto rF, ll nd) -> void {
    if (onStack[nd]) return;
    onStack[nd] = true;
    stack.push_back(nd);
    cnt++;
    if (cnt >= lim) throw myexc();
    for (ll peer : nbr[nd]) rF(rF, peer);
    stack.pop_back();
    onStack[nd] = false;
  };
  try {
    dfs(dfs, 0);
  }catch(myexc& e) {
  }
  cout << cnt << endl;

  return 0;
}

