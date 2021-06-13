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

  ll x, y; cin >> x >> y;
  if (x == y) {
    cout << x << endl;
  }else {
    vector<ll> A(3);
    A[x] = 1;
    A[y] = 1;
    for (ll i = 0; i < 3; i++) {
      if (A[i] == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}

