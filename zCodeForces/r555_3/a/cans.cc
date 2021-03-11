#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;

  auto f = [&](ll x) -> ll {
    x++;
    while (x % 10 == 0) x /= 10;
    return x;
  };

  set<ll> xs;
  xs.insert(n);
  while (true) {
    n = f(n);
    if (xs.find(n) == xs.end()) {
      xs.insert(n);
    }else {
      break;
    }
  }
  cout << xs.size() << endl;


  return 0;
}

