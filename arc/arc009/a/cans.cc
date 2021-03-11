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
  ll s = 0;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    s += a * b;
  }
  cout << s * 105 / 100 << endl;

  return 0;
}

