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

  auto solve = [&]() -> void{
    ll n; cin >> n;
    if (n % 2 == 1) {
      cout << "Odd\n";
      return;
    }
    n /= 2;
    if (n % 2 == 1) {
      cout << "Same\n";
      return;
    }
    cout << "Even\n";
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

