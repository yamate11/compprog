#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll k; cin >> k;
  
  if (k > 36) {
    cout << -1 << endl;
  }else {
    for (ll i = 0; i < k / 2; i++) {
      cout << 8;
    }
    if (k % 2 == 1) {
      cout << 6;
    }
    cout << endl;
  }


  return 0;
}

