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

  ll a, b, c; cin >> a >> b >> c;
  ll ans = 0;
  ans = max(ans, a + b);
  ans = max(ans, b + c);
  ans = max(ans, a + c);
  cout << ans << endl;

  return 0;
}

