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
  if (n == 2) {
    cout << "1\n2\n";
    return 0;
  }else if (n % 2 == 0) {
    cout << n / 2 << endl;
    for (ll i = 0; i < n / 2; i++) {
      if (i > 0) cout << " ";
      cout << 2;
    }
    cout << endl;
    return 0;
  }else {
    ll p = (n - 1) / 2;
    cout << p << endl << "3";
    for (ll i = 0; i < p - 1; i++) {
      cout << " 2";
    }
    cout << endl;
    return 0;
  }
  


  return 0;
}

