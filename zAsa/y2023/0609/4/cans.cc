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
  // @InpVec(N, C) [VjunJdTt]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [VjunJdTt]
  // @InpNbrList(N, N - 1, nbr, dec=1) [w7nnZLH2]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [w7nnZLH2]
  ll lim = (ll)(1e5) + 1;
  vector<ll> cnt(lim);
  vector<ll> ans;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (cnt[C[nd]] == 0) ans.push_back(nd);
    cnt[C[nd]]++;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    cnt[C[nd]]--;
  };
  dfs(dfs, 0, -1);
  sort(ALL(ans));
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, "\n");

  return 0;
}

