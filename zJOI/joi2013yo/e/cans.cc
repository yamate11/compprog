#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> X1(N), Y1(N), Z1(N), X2(N), Y2(N), Z2(N);
  vector<ll> X, Y, Z;
  for (ll i = 0; i < N; i++) {
    cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i];
    X.push_back(X1[i]);
    X.push_back(X2[i]);
    Y.push_back(Y1[i]);
    Y.push_back(Y2[i]);
    Z.push_back(Z1[i]);
    Z.push_back(Z2[i]);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  sort(Z.begin(), Z.end());
  
  ll nX = X.size(), nY = Y.size(), nZ = Z.size();
  vector P(nX, vector(nY, vector(nZ, 0LL)));
  for (ll i = 0; i < N; i++) {
    ll x1 = lower_bound(X.begin(), X.end(), X1[i]) - X.begin();
    ll x2 = lower_bound(X.begin(), X.end(), X2[i]) - X.begin();
    ll y1 = lower_bound(Y.begin(), Y.end(), Y1[i]) - Y.begin();
    ll y2 = lower_bound(Y.begin(), Y.end(), Y2[i]) - Y.begin();
    ll z1 = lower_bound(Z.begin(), Z.end(), Z1[i]) - Z.begin();
    ll z2 = lower_bound(Z.begin(), Z.end(), Z2[i]) - Z.begin();
    P[x1][y1][z1] += 1;
    P[x2][y1][z1] -= 1;
    P[x1][y2][z1] -= 1;
    P[x1][y1][z2] -= 1;
    P[x1][y2][z2] += 1;
    P[x2][y1][z2] += 1;
    P[x2][y2][z1] += 1;
    P[x2][y2][z2] -= 1;
  }
  ll ans = 0;
  vector Q(nX + 1, vector(nY + 1, vector(nZ + 1, 0LL)));
  for (ll x = 0; x < nX; x++) {
    for (ll y = 0; y < nY; y++) {
      for (ll z = 0; z < nZ; z++) {
	ll q = Q[x+1][y+1][z+1] = P[x][y][z]
	  + Q[x][y+1][z+1] + Q[x+1][y][z+1] + Q[x+1][y+1][z]
	  - Q[x+1][y][z] - Q[x][y+1][z] - Q[x][y][z+1]
	  + Q[x][y][z];
	if (q < K) continue;
	ans += (X[x+1] - X[x]) * (Y[y+1] - Y[y]) * (Z[z+1] - Z[z]);
      }
    }
  }
  cout << ans << endl;
  

  return 0;
}

