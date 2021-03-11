#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> X(N), Y(N), P(N);
  for (ll i = 0; i < N; i++) {
    ll x, y, p; cin >> x >> y >> p;
    X.at(i) = x;
    Y.at(i) = y;
    P.at(i) = p;
  }

  ll pssize = 1LL << N;
  vector distX(pssize, vector(N, 0LL));
  vector distY(pssize, vector(N, 0LL));
  for (ll t = 0; t < pssize; t++) {
    for (ll i = 0; i < N; i++) {
      ll vminx = abs(X.at(i));
      ll vminy = abs(Y.at(i));
      for (ll j = 0; j < N; j++) {
	if (t & (1LL << j)) {
	  vminx = min(vminx, abs(X.at(i) - X.at(j)));
	  vminy = min(vminy, abs(Y.at(i) - Y.at(j)));
	}
      }
      distX.at(t).at(i) = vminx;
      distY.at(t).at(i) = vminy;
    }
  }

  vector<ll> ans(N+1, LLONG_MAX);
  for (ll tt = 0; tt < pssize; tt++) {
    ll k = __builtin_popcountll(tt);
    for (ll tx = tt; true; tx = (tx - 1) & tt) {
      ll ty = tt ^ tx;
      ll sum = 0;
      for (ll i = 0; i < N; i++) {
	sum += min(distX[tx][i], distY[ty][i]) * P[i];
      }
      ans.at(k) = min(ans.at(k), sum);
      if (tx == 0) break;
    }
  }

  for (ll i = 0; i <= N; i++) cout << ans.at(i) << "\n";

  return 0;
}

