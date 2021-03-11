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

  // ll xxx = inv_mod(3, 10);
  // assert(xxx == 7);

  ll m, n, N; cin >> m >> n >> N;
  ll ans = N;
  ll stock = 0;
  ll cur = N;
  while (cur > 0) {
    ll tot = stock + cur;
    stock = tot % m;
    cur = (tot / m) * n;
    ans += cur;
  }
  cout << ans << endl;

  return 0;
}

