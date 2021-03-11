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
    ll N, M; cin >> N >> M;
    vector<ll> A(N), P(M);
    for (ll i = 0; i < N; i++) cin >> A[i];
    for (ll i = 0; i < M; i++) {
      cin >> P[i]; P[i]--;
    }
    sort(P.begin(), P.end());
    vector<bool> starts(N, true);
    for (ll i = 0; i < M; i++) {
      starts[P[i] + 1] = false;
    }

    ll gmax = -1;
    ll lmax = -1;

    for (ll i = 0; i < N; i++) {
      if (starts[i]) {
	gmax = max(gmax, lmax);
	lmax = -1;
      }
      if (A[i] < gmax) {
	cout << "NO\n";
	return;
      }
      lmax = max(lmax, A[i]);
    }
    cout << "YES\n";
    return;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

