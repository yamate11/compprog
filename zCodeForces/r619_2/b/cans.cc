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
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    ll vmax = -1;
    ll vmin = 1e10;
    ll adiff = 0;
    for (ll i = 0; i < N; i++) {
      if (A[i] == -1) {
	if (i-1 >= 0 && A[i-1] != -1) {
	  vmax = max(vmax, A[i-1]);
	  vmin = min(vmin, A[i-1]);
	}
	if (i+1 < N && A[i+1] != -1) {
	  vmax = max(vmax, A[i+1]);
	  vmin = min(vmin, A[i+1]);
	}
      }else if (i+1 < N && A[i+1] != -1) {
	adiff = max(adiff, abs(A[i+1] - A[i]));
      }
    }
    ll k, m;
    if (vmax == -1 && vmin == 1e10) {
      k = 1; m = 0;
    }else {
      k = (vmax + vmin) / 2;
      m = max(vmax - k, k - vmin);
      m = max(m, adiff);
    }
    cout << m << " " << k << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

