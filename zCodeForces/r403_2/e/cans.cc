#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k; cin >> n >> m >> k;
  ll cap = (2 * n + (k-1)) / k;
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < m; i++) {
    ll x, y; cin >> x >> y; x--; y--;
    nbr[x].push_back(y);
    nbr[y].push_back(x);
  }
  vector<bool> visited(n);
  ll agent = 0;
  ll step = 0;
  vector<ll> rec;
  auto rec_flush = [&]() -> void {
    if (step == 0) return;
    cout << step;
    for (ll r : rec) {
      cout << " " << r + 1;
    }
    cout << "\n";
    rec.resize(0);
    step = 0;
    agent++;
  };
  auto report = [&](ll nd) -> void {
    rec.push_back(nd);
    step++;
    if (step == cap) rec_flush();
  };
  auto dfs = [&](auto rF, ll nd) -> bool {
    if (visited[nd]) return false;
    visited[nd] = true;
    report(nd);
    // bool csucc = false;
    for (ll nxt : nbr[nd]) {
      bool cs = rF(rF, nxt);
      if (cs) report(nd);
      // csucc = csucc || cs;
    }
    // if (csucc) report(nd);
    return true;
  };
  dfs(dfs, 0);
  rec_flush();
  for (; agent < k; agent++) {
    cout << "1 1\n";
  }

  return 0;
}

