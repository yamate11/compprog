#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, q; cin >> n >> m >> q;
  using sta = tuple<ll, ll, ll>;
  vector<sta> op;
  op.emplace_back(-1, -1, -1);
  vector<vector<ll>> child(q + 1);
  for (ll i = 1; i <= q; i++) {
    ll tp; cin >> tp;
    if (tp == 1 || tp == 2) {
      ll x, y; cin >> x >> y; x--; y--;
      op.emplace_back(tp, x, y);
      child[i-1].push_back(i);
    }else if (tp == 3) {
      ll x; cin >> x; x--;
      op.emplace_back(tp, x, -1);
      child[i-1].push_back(i);
    }else if (tp == 4) {
      ll k; cin >> k;
      op.emplace_back(tp, k, -1);
      child[k].push_back(i);
    }
  }
  vector<ll> szst(q + 1);
  auto dfs = [&](auto rF, ll nd) -> ll {
    ll cnt = 1;
    for (ll c : child[nd]) cnt += rF(rF, c);
    szst[nd] = cnt;
    return cnt;
  };
  dfs(dfs, 0);
  vector<ll> ans(q + 1);
  vector curT(n, vector(m, false));
  ll curN = 0;
  auto dfs2 = [&](auto rF, ll nd) -> void {
    if (nd >= 1) {
      auto [tp, x, y] = op[nd];
      if (tp == 1) {
	if (! curT[x][y]) curN++;
	curT[x][y] = true;
      }else if (tp == 2) {
	if (curT[x][y]) curN--;
	curT[x][y] = false;
      }else if (tp == 3) {
	for (ll j = 0; j < m; j++) {
	  if (curT[x][j]) {
	    curN--;
	    curT[x][j] = false;
	  }else {
	    curN++;
	    curT[x][j] = true;
	  }
	}
      }else if (tp == 4) {
      }
    }
    ans[nd] = curN;
    ll sz = child[nd].size();
    vector<vector<bool>> remT;
    ll remN = curN;
    if (sz >= 2) {
      remT = curT;
      sort(child[nd].begin(), child[nd].end(),
	   [&](ll x, ll y) -> bool { return szst[x] < szst[y]; });
    }
    for (ll j = 0; j < sz; j++) {
      if (j > 0) {
	if (j == sz - 1) curT = move(remT);
	else             curT = remT;
	curN = remN;
      }
      rF(rF, child[nd][j]);
    }
  };
  dfs2(dfs2, 0);
  for (ll i = 1; i <= q; i++) {
    cout << ans[i] << "\n";
  }



  return 0;
}

