#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, N; cin >> H >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  vector<vector<ll>> dp(N+1, vector<ll>(H+1, 1e10));
  dp.at(0).at(0) = 0;
  for (ll i = 0; i < N; i++) {
    ll a = A.at(i);
    dp.at(i+1).at(0) = 0;
    for (ll j = 1; j <= H; j++) {
      ll base = j-a >= 0 ? dp.at(i+1).at(j-a) : 0;
      dp.at(i+1).at(j) = min(dp.at(i).at(j), base + B.at(i));
    }
  }
  cout << dp.at(N).at(H) << endl;

  return 0;
}

