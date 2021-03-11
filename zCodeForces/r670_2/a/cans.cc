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
    ll N; cin >> N;
    vector<ll> vec(101);
    for (ll i = 0; i < N; i++) {
      ll a; cin >> a;
      vec[a]++;
    }
    ll x1 = 0;
    for (ll i = 0; i <= 100; i++) {
      if (vec[i] == 0) {
	x1 = i;
	break;
      }
    }
    ll x2 = 0;
    for (ll i = 0; i <= 100; i++) {
      if (vec[i] <= 1) {
	x2 = i;
	break;
      }
    }
    cout << x1 + x2 << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();


  return 0;
}

