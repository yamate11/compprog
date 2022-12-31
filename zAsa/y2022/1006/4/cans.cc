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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [Ty4mWIrn]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [Ty4mWIrn]
  auto func = [&](ll root) -> ll {
    ll ans = 0;
    vector<bool> seen(N);
    seen[root] = true;
    for (ll p : nbr[root]) seen[p] = true;
    for (ll p : nbr[root]) {
      for (ll q : nbr[p]) if (not seen[q]) {
          seen[q] = true;
          ans++;
        }
    }
    return ans;
  };
  vector<ll> ans(N);
  REP(i, 0, N) ans[i] = func(i);
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

