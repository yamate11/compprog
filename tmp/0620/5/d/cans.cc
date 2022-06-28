#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector nbr(N, vector<ll>());
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  vector<ll> C(N); REP(i, N) cin >> C[i];
  if (N == 1) {
    cout << 0 << endl << endl;
    return 0;
  }
  if (N == 2) {
    cout << min(C[0], C[1]) << endl << C[0] << " " << C[1] << endl;
    return 0;
  }
  sort(ALL(C));
  vector<ll> ans(N);
  ll idx = 0;
  ll M = 0;
  ll root = 0;
  for ( ; ; root++) if (SIZE(nbr[root]) >= 2) break;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    ans[nd] = C[idx++];
    if (nd != root) M += ans[nd];
  };
  dfs(dfs, root, -1);
  cout << M << endl;
  for (ll a : ans) cout << a << " ";
  cout << endl;

  return 0;
}

