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

  ll L, R; cin >> L >> R;
  vector<ll> vec(R + 1);
  ll cnt = 0;
  for (ll g = R; g >= 2; g--) {
    ll q = R / g - (L - 1) / g;
    vec[g] = q * q;
    for (ll p = g + g; p <= R; p += g) vec[g] -= vec[p];
    cnt += vec[g];
  }
  for (ll g = R; g >= max(2LL, L); g--) {
    cnt -= 2 * (R / g) - 1;
  }
  cout << cnt << endl;

  return 0;
}

