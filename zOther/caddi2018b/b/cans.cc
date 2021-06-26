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

  ll N, H, W; cin >> N >> H >> W;
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    if ((H <= a) && (W <= b)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

