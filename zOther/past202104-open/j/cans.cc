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

  ll N, C; cin >> N >> C;
  vector<ll> X(N), Y(N);
  ll xsum = 0, ysum = 0;
  for (ll i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    xsum += X[i];
    ysum += Y[i];
  }
  double gx = (double)xsum / N;
  double cost = 0.0;
  for (ll i = 0; i < N; i++) {
    cost += (gx - X[i]) * (gx - X[i]);
    cost += (C - Y[i]) * (C - Y[i]);
  }
  cout << cost << endl;

  return 0;
}

