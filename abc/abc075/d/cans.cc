#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  using Pair = pair<ll, ll>;
  vector<ll> X, Y;
  vector<Pair> P;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    X.push_back(x);
    Y.push_back(y);
    P.emplace_back(x, y);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  // sort(P.begin(), P.end());
  ll ans = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    ll p = Y.at(i);
    for (ll j = i+1; j < N; j++) {
      ll q = Y.at(j);
      for (ll k = 0; k < N; k++) {
	ll r = X.at(k);
	for (ll l = k+1; l < N; l++) {
	  ll s = X.at(l);
	  ll cnt = 0;
	  for (ll m = 0; m < N; m++) {
	    ll x = P.at(m).first;
	    ll y = P.at(m).second;
	    if (r <= x && x <= s && p <= y && y <= q) cnt++;
	  }
	  if (cnt >= K) ans = min(ans, (q - p) * (s - r));
	}
      }
    }
  }
  cout << ans << endl;

  return 0;
}

