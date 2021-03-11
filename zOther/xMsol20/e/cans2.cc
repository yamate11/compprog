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

  vector rail(N, int8_t(0));
  auto rnext = [&]() -> bool {
    ll i = 0;
    while (i < N && rail.at(i) == 2) {
      rail.at(i) = 0;
      i++;
    }
    if (i == N) return false;
    rail.at(i)++;
    return true;
  };

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
  do {
    ll tx = 0;
    ll ty = 0;
    ll k = 0;
    for (ll i = 0; i < N; i++) {
      if (rail.at(i) == 1) tx |= (1LL << i);
      if (rail.at(i) == 2) ty |= (1LL << i);
      if (rail.at(i) != 0) k++;
    }
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
      sum += min(distX.at(tx).at(i), distY.at(ty).at(i)) * P.at(i);
    }
    ans.at(k) = min(ans.at(k), sum);
  }while (rnext());

  for (ll i = 0; i <= N; i++) cout << ans.at(i) << endl;

  return 0;
}

