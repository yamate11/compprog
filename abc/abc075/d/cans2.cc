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
  // sort(X.begin(), X.end());
  sort(P.begin(), P.end());
  sort(Y.begin(), Y.end());
  ll ans = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    ll p = Y.at(i);
    for (ll j = i+1; j < N; j++) {
      ll q = Y.at(j);
      vector<ll> vec;
      for (ll k = 0; k < N; k++) {
	const Pair& pr = P.at(k);
	if (p <= pr.second && pr.second <= q) vec.push_back(pr.first);
      }
      ll M = vec.size();
      if (M < K) continue;
      for (ll k = 0; k + (K-1) < M; k++) {
	ans = min(ans, (vec.at(k + (K-1)) - vec.at(k)) * (q - p));
      }
    }
  }
  cout << ans << endl;

  return 0;
}

