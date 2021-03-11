#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  for (ll i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      for (ll k = j+1; k < N; k++) {
	ll p = X.at(k) - X.at(i);
	ll q = Y.at(k) - Y.at(i);
	ll u = X.at(j) - X.at(i);
	ll v = Y.at(j) - Y.at(i);
	ll ss = abs(p * v - q * u);
	if (ss != 0 && ss % 2 == 0) cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

