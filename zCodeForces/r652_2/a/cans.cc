#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll _t = 0; _t < t; _t++) {
    ll n; cin >> n;
    if (n % 4 == 0) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  }


  return 0;
}

