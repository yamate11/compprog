#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, ll m, auto& a, auto& b) -> void {
    set<ll> as;
    for (ll x : a) as.insert(x);
    for (ll x : b) {
      if (as.find(x) != as.end()) {
	cout << "YES\n1 " << x << "\n";
	return;
      }
    }
    cout << "NO\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) cin >> a.at(i);
    for (ll i = 0; i < m; i++) cin >> b.at(i);
    solve(n, m, a, b);
  }
  

  return 0;
}

