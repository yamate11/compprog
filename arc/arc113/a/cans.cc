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

  ll K; cin >> K;
  ll cnt = 0;
  for (ll a = 1; a <= K; a++) {
    for (ll b = 1; b <= K / a; b++) {
      cnt += K / a / b;
    }
  }
  cout << cnt << endl;

  return 0;
}

