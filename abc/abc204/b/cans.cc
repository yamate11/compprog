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
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a <= 10) continue;
    ans += a - 10;
  }
  cout << ans << endl;

  return 0;
}

