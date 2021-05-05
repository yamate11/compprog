#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> nbr(N + 1);
  for (ll i = 0; i < N - 1; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  auto rec = vector(2, vector<ll>());
  auto dfs = [&](auto rF, ll nd, ll pt, ll lev) -> void {
    rec[lev % 2].push_back(nd);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd, lev + 1);
    }
  };
  dfs(dfs, 1, -1, 0);
  ll idx = rec[0].size() > rec[1].size() ? 0 : 1;
  for (ll i = 0; i < N / 2; i++) {
    cout << rec[idx][i] << " ";
  }
  cout << endl;
  return 0;
}

