#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Pair = pair<ll, ll>;

  auto solve = [&](ll n, ll k, auto& edges) -> ll {
    if (k == 1) return n - 1;

    vector<set<ll>> nbr(n);
    for (auto [x, y] : edges) {
      nbr.at(x).insert(y);
      nbr.at(y).insert(x);
    }
    vector<set<ll>> nbr_leaves(n);
    for (ll i = 0; i < n; i++) {
      if (nbr.at(i).size() == 1) {
	ll p = *(nbr.at(i).begin());
	nbr_leaves.at(p).insert(i);
      }
    }
    queue<ll> pend;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
      if ((ll)nbr_leaves.at(i).size() >= k) pend.push(i);
    }
    while (!pend.empty()) {
      ll i = pend.front(); pend.pop();
      ll u = nbr_leaves.at(i).size() / k;
      cnt += u;
      ll j = 0;
      for (auto it = nbr_leaves.at(i).begin(); j < k * u; j++) {
	nbr.at(i).erase(*it);
	it = nbr_leaves.at(i).erase(it);
      }
      if (nbr.at(i).size() == 1) {
	ll p = *(nbr.at(i).begin());
	nbr_leaves.at(p).insert(i);
	if ((ll)nbr_leaves.at(p).size() == k) pend.push(p);
      }
    }
    return cnt;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, k; cin >> n >> k;
    vector<Pair> edges;
    for (ll i = 0; i < n-1; i++) {
      ll x, y; cin >> x >> y; x--; y--;
      edges.emplace_back(x, y);
    }
    cout << solve(n, k, edges) << "\n";
  }

  return 0;
}

