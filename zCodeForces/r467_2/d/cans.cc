#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<vector<ll>> nxt(n + 1), prv(n + 1);
  for(ll i = 1; i <= n; i++) {
    ll c; cin >> c;
    for (ll j = 0; j < c; j++) {
      ll k; cin >> k;
      nxt[i].push_back(k);
      prv[k].push_back(i);
    }
  }
  ll root; cin >> root;
  vector<ll> terms;
  vector<bool> visited(n + 1);
  vector<bool> ongoing(n + 1);
  bool has_cycle = false;
  auto dfs = [&](auto rF, ll nd) -> void {
    if (ongoing[nd]) {
      has_cycle = 1;
      return;
    }
    if (visited[nd]) return;
    visited[nd] = true;
    if (nxt[nd].empty()) {
      terms.push_back(nd);
      return;
    }
    ongoing[nd] = true;
    for (ll cld: nxt[nd]) rF(rF, cld);
    ongoing[nd] = false;
    return;
  };
  dfs(dfs, root);
  vector<vector<ll>> route_next(2, vector<ll>(n + 1, -1LL));
  using que_t = pair<ll, ll>;
  queue<que_t> que;
  const ll T_EVEN = 0;
  const ll T_ODD = 1;
  for (ll t : terms) {
    que.emplace(t, T_EVEN);
    route_next[T_EVEN][t] = t;
  }
  while (!que.empty()) {
    auto [nd, tp] = que.front(); que.pop();
    for (ll pt : prv[nd]) {
      ll newtp = 1 - tp;
      if (route_next[newtp][pt] >= 0) continue;
      route_next[newtp][pt] = nd;
      que.emplace(pt, newtp);
    }
  }
  if (route_next[T_ODD][root] >= 0) {
    cout << "Win\n";
    ll nd = root;
    ll tp = T_ODD;
    bool first = true;
    while (true) {
      if (first) first = false;
      else cout << " ";
      cout << nd;
      ll newnd = route_next[tp][nd];
      if (nd == newnd) break;
      nd = newnd;
      tp = 1 - tp;
    }
    cout << endl;
  }else if (has_cycle) {
    cout << "Draw\n";
  }else {
    cout << "Lose\n";
  }
    

  return 0;
}

