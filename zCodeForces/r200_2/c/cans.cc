#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](auto rF, ll a, ll b) -> ll {
    if (a == 0) return 0;
    if (a >= b) {
      ll x = a / b;
      ll y = a % b;
      return rF(rF, y, b) + x;
    }
    return rF(rF, b - a, a) + 1;
  };

  ll a, b; cin >> a >> b;
  cout << f(f, a, b) << endl;


  return 0;
}

