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
    vector<ll> p(N), q(N);
    for (ll i = 0; i < N; i++) {
      ll a; cin >> a; a--;
      p[i] = a;
      q[a] = i;
    }
    ll imax = q[0];
    ll imin = q[0];
    for (ll i = 1; i < N; i++) {
      if (imax + 1 < q[i]) {
	cout << "YES\n";
	cout << imax + 1 << " " << imax + 2 << " " << q[i] + 1 << "\n";
	return;
      }else if (q[i] < imin - 1) {
	cout << "YES\n";
	cout << q[i] + 1 << " " << imin << " " << imin + 1 << "\n";
	return;
      }else {
	imax = max(imax, q[i]);
	imin = min(imin, q[i]);
      }
    }
    cout << "NO\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

