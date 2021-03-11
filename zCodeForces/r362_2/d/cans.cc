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
  vector<vector<ll>> child(n);
  for (ll i = 1; i < n; i++) {
    ll p; cin >> p; p--;
    child[p].push_back(i);
  }
  vector<ll> numst(n);
  auto dfs1 = [&](auto rF, ll nd) -> ll {
    ll cnt = 1;
    for (ll c : child[nd]) cnt += rF(rF, c);
    numst[nd] = cnt;
    return cnt;
  };
  dfs1(dfs1, 0);
  vector<double> exp(n);
  auto dfs2 = [&](auto rF, ll nd, double e) -> void {
    exp[nd] = e;
    ll m = numst[nd] - 1;
    for (ll c : child[nd]) {
      double ce = e + 1 + double(m - numst[c]) / 2.0;
      rF(rF, c, ce);
    }
  };
  dfs2(dfs2, 0, 1.0);
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << exp[i];
  }
  cout << endl;

  return 0;
}

