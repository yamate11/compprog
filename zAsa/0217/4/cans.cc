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

  ll N; cin >> N;
  vector nbr(N, vector(0, 0LL));
  REP(i, 0, N - 1) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll a_leaf = 0;
  for(; ssize(nbr[a_leaf]) != 1; a_leaf++);
  vector ans(0, 0LL);
  auto dfs = [&](auto rF, ll nd, ll pt, ll dp) -> void {
    if (dp % 3 == 0) ans.push_back(ssize(nbr[nd]));
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd, dp + 1);
    }
  };
  dfs(dfs, nbr[a_leaf][0], -1, 0);
  sort(ALL(ans));
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

