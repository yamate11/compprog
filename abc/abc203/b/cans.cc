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

  ll N, K; cin >> N >> K;
  ll sum = 0;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j <= K; j++) {
      sum += 100 * i + j;
    }
  }
  cout << sum << endl;

  return 0;
}

