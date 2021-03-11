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
    ll n; cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      A[i] = a;
    }
    ll x = A[0];
    ll p = 1;
    ll y = -1;
    for (; p < n; p++) {
      if (A[p] != x) {
	y = A[p];
	break;
      }
    }
    if (y == -1) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    auto conn = [&](ll u, ll v) -> void {
      cout << u + 1 << " " << v + 1 << "\n";
    };
    conn(0, p);
    for (ll i = 1; i < n; i++) {
      if (i == p) continue;
      if (A[i] == x) conn(p, i);
      else conn(0, i);
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

