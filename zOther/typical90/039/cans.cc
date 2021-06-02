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
  auto nbr = vector(N + 1, vector<ll>());
  for (ll i = 0; i < N - 1; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll ans = 0;
  auto dfs = [&](auto rF, ll nd, ll pt) -> ll {
    ll ret = 1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      ll m = rF(rF, cld, nd);
      ans += m * (N - m);
      ret += m;
    }
    return ret;
  };
  dfs(dfs, 1, -1);
  cout << ans << endl;

  return 0;
}

