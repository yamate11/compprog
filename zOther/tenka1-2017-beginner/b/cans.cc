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
  ll amax = -1;
  ll val = -1;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    if (amax < a) {
      amax = a;
      val = b;
    }
  }
  cout << amax + val << endl;

  return 0;
}

