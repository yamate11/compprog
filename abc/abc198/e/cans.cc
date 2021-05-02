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

  ll lim = 1e5;
  ll N; cin >> N;
  vector<ll> C(N + 1);
  for (ll i = 1; i <= N; i++) cin >> C[i];
  auto nbr = vector(N + 1, vector<ll>());
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  vector<ll> ans;
  vector<ll> numcols(lim + 1);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (numcols[C[nd]] == 0) ans.push_back(nd);
    numcols[C[nd]]++;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    numcols[C[nd]]--;
  };
  dfs(dfs, 1, -1);
  sort(ans.begin(), ans.end());
  for (ll a : ans) {
    cout << a << "\n";
  }

  return 0;
}

