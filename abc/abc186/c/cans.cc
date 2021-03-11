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
  ll cnt = 0;
  auto contain = [&](ll x, ll base) -> bool {
    while (x > 0) {
      ll p = x % base;
      if (p == 7) return true;
      x /= base;
    }
    return false;
  };

  for (ll i = 1; i <= N; i++) {
    if (!contain(i, 8) && !contain(i, 10)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

