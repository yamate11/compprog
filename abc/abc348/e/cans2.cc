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

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1) [ZDbTULXC]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [ZDbTULXC]
  // @InpVec(N, C) [2gPg9Fjy]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [2gPg9Fjy]
  vector X(N, 0LL);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    X[nd] = C[nd];
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      X[nd] += X[cld];
    }
  };
  dfs(dfs, 0, -1);
  ll tot = X[0];
  vector Y(N, 0LL);
  Y[0] = accumulate(X.begin() + 1, X.end(), 0LL);
  auto dfs2 = [&](auto rF, ll nd, ll pt) -> void {
    if (pt >= 0) {
      ll z = tot - X[nd];
      Y[nd] = Y[pt] - X[nd] + z;
    }
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
  };
  dfs2(dfs2, 0, -1);
  ll ans = *min_element(ALL(Y));
  cout << ans << endl;

  return 0;
}

