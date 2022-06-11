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
  vector<ll> A(N - 1), B(N - 1);
  vector nbr(N, vector<ll>());
  map<ll, map<ll, ll>> mp;
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
    mp[a][b] = i;
    mp[b][a] = i;
  }
  vector<ll> ans(N - 1);
  ll cnum = 0;
  auto dfs = [&](auto rF, ll nd, ll pt, ll col) -> void {
    ll i = 0;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      if (i == col) i++;
      ans[mp[nd][cld]] = i + 1;
      rF(rF, cld, nd, i);
      i++;
    }
    cnum = max(cnum, i);
  };
  dfs(dfs, 0, -1, -1);
  cout << cnum << "\n";
  for (ll a : ans) cout << a << "\n";

  return 0;
}

