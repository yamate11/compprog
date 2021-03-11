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
  auto f = [&](ll x) -> ll {
    return x * (x + 1) / 2;
  };
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    s += f(b) - f(a-1);
  }
  cout << s << endl;

  return 0;
}

