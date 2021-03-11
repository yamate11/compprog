#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  for (ll i = 0; i < N; i++) cin >> X[i] >> Y[i];
  for (ll i = 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      for (ll k = j+1; k < N; k++) {
	ll p = X[j] - X[i];
	ll q = Y[j] - Y[i];
	ll u = X[k] - X[i];
	ll v = Y[k] - Y[i];
	if (p* v == q * u) {
	  cout << "Yes\n";
	  return 0;
	}
      }
    }
  }
  cout << "No\n";

  return 0;
}

