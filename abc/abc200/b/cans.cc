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
  for (ll i = 0; i < K; i++) {
    if (N % 200 == 0) {
      N /= 200;
    }else {
      N *= 1000;
      N += 200;
    }
  }
  cout << N << endl;

  return 0;
}

