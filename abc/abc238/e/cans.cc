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

  ll N, Q; cin >> N >> Q;
  vector<vector<ll>> nbr(N + 1);
  REP(i, Q) {
    ll l, r; cin >> l >> r; l--;
    nbr[l].push_back(r);
    nbr[r].push_back(l);
  }
  vector<bool> visited(N + 1);
  auto dfs = [&](auto rF, ll n) -> void {
    if (visited[n]) return;
    visited[n] = true;
    for (ll y : nbr[n]) rF(rF, y);
  };
  dfs(dfs, 0);
  if (visited[N]) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

