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

  auto solve = []() -> ll {
    ll L, R; cin >> L >> R;
    ll ans = 0;
    if (2*L <= R) {
      ans = (R - 2*L + 1) * (R - 2*L + 2) / 2;
    }else {
      ans = 0;
    }
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";
  

  return 0;
}

