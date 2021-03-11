#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  for (ll i = 1; i <= 5; i++) {
    ll x; cin >> x;
    if (x == 0) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

