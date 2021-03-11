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

  ll N, X; cin >> N >> X;
  vector<ll> V(N), P(N);
  for (ll i = 0; i < N; i++) cin >> V[i] >> P[i];
  ll t = 0;
  for (ll i = 0; i < N; i++) {
    t += V[i] * P[i];
    if (t > X * 100) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}

