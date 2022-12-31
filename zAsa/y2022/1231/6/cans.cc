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
  // @InpVec(N, A) [0uvlb4At]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [0uvlb4At]
  // @InpNbrList(N, N - 1, nbr, dec=1) [6CCJFxij]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [6CCJFxij]
  vector<ll> ans(N);
  vector<ll> vec;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    ll idx = lower_bound(ALL(vec), A[nd]) - vec.begin();
    bool appended = false;
    ll old_val = -1;
    if (idx == SIZE(vec)) {
      appended = true;
      vec.push_back(A[nd]);
    }else {
      old_val = vec[idx];
      vec[idx] = A[nd];
    }
    ans[nd] = SIZE(vec);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    if (appended) {
      vec.pop_back();
    }else {
      vec[idx] = old_val;
    }
  };
  dfs(dfs, 0, -1);
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

