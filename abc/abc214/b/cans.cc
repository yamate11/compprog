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

  ll S, T; cin >> S >> T;
  ll cnt = 0;
  for (ll a = 0; a <= S; a++) {
    for (ll b = 0; b <= S - a; b++) {
      for (ll c = 0; c <= S - a - b; c++) {
        if (a * b * c <= T) cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}

