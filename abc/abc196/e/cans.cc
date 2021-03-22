#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  const ll big = 1e16;
  ll amax = -big;
  ll amin = big;
  ll asum = 0;

  for (ll i = 0; i < N; i++) {
    ll a, t; cin >> a >> t;
    if (t == 1) {
      asum += a;
      amax += a;
      amin += a;
    } else if (t == 2) {
      amax = max(amax, a);
      amin = max(amin, a);
    } else {
      amax = min(amax, a);
      amin = min(amin, a);
    }
  }

  ll Q; cin >> Q;
  for (ll q = 0; q < Q; q++) {
    ll x; cin >> x;
    cout << max(min(x + asum, amin), amax) << "\n";
  }
  return 0;
}
