#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void minUpd(ll& x, const ll y) { x = min(x, y); }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1000LL * 400 * 10 + 10;
  ll N, M; cin >> N >> M;
  // vector<vector<ll>> ud(N, vector<ll>(N, big));
  vector<vector<ll>> dist(N, vector<ll>(N, big));
  for (ll i = 0; i < N; i++) dist.at(i).at(i) = 0;
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    dist.at(a).at(b) = dist.at(b).at(a) = c;
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      for (ll k = 0; k < N; k++) {
	minUpd(dist.at(j).at(k), dist.at(j).at(i) + dist.at(i).at(k));
      }
    }
  }
  ll K; cin >> K;
  for (ll p = 0; p < K; p++) {
    ll X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
	minUpd(dist.at(i).at(j),
	       min(dist.at(i).at(X) + dist.at(Y).at(j) + Z,
		   dist.at(i).at(Y) + dist.at(X).at(j) + Z));
      }
    }
    ll S = 0;
    for (ll i = 0; i < N; i++) {
      for (ll j = i+1; j < N; j++) S += dist.at(i).at(j);
    }
    cout << S << "\n";
  }

  return 0;
}

