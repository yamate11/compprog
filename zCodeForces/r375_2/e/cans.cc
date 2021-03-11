#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, m; cin >> n >> m;
    vector<set<ll>> nbr(n);
    for (ll i = 0; i < m; i++) {
      ll u, v; cin >> u >> v; u--; v--;
      nbr[u].insert(v);
      nbr[v].insert(u);
    }
    vector<ll> odds;
    for (ll i = 0; i < n; i++) {
      if (nbr[i].size() % 2 == 1) odds.push_back(i);
    }
    using sta = pair<ll, ll>;
    vector<sta> ans;
    auto follow = [&](ll p) -> void {
      while (!nbr[p].empty()) {
	auto it = nbr[p].begin();
	ll q = *it;
	nbr[p].erase(it);
	ans.emplace_back(p, q);
	nbr[q].erase(p);
	p = q;
      }
    };

    for (ll p : odds) follow(p);
    for (ll p = 0 ; p < n; p++) {
      if (!nbr[p].empty()) follow(p);
    }

    cout << n - odds.size() << "\n";
    for (auto [p, q] : ans) {
      cout << p + 1 << " " << q + 1 << "\n";
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

