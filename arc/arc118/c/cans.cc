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

  ll N; cin >> N;
  cout << 3*5*7*11 << " " << 6 << " " << 10;

  ll cnt = 3;
  for (ll i = 2; i < 10000; i++) {
    if (cnt == N) break;
    if (i % 2 == 1) continue;
    if (i == 6 || i == 10) continue;
    if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0) {
      cout << " " << i;
      cnt++;
    }
  }
  cout << endl;

  return 0;
}

