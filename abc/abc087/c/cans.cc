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
  vector<vector<ll>> vec(2, vector<ll>(N));
  for (ll i = 0; i < N; i++) cin >> vec.at(0).at(i);
  for (ll i = 0; i < N; i++) cin >> vec.at(1).at(i);
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll s = 0;
    ll r = 0;
    for (ll j = 0; j < N; j++) {
      s += vec.at(r).at(j);
      if (j == i) {
	r = 1;
	s += vec.at(r).at(j);
      }
      ans = max(ans, s);
    }
  }
  cout << ans << endl;

  return 0;
}

