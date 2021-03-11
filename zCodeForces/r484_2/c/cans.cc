#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<vector<ll>> nbr(n + 1);
  for (ll i = 0; i < n - 1; i++) {
    ll p, q; cin >> p >> q;
    nbr[p].push_back(q);
    nbr[q].push_back(p);
  }
  /*
  nbr[0].push_back(1);
  nbr[1].push_back(0);
  */
  ll ans = 0;
  auto dfs = [&](auto rF, ll nd, ll prt) -> ll {
    ll cnt = 1;
    for (ll cld : nbr[nd]) {
      if (cld == prt) continue;
      cnt += rF(rF, cld, nd);
    }
    if (cnt % 2 == 0) {
      ans += 1;
      return 0;
    }else {
      return cnt;
    }
  };
  ll t = dfs(dfs, 1, -1);
  if (t == 0) {
    cout << ans - 1 << endl;
  }else {
    cout << -1 << endl;
  }

  return 0;
}

