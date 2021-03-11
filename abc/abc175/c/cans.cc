#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, K, D; cin >> X >> K >> D;
  if (X < 0) X = -X;
  ll t = X / D;
  if (t > K) {
    cout << X - D * K << endl;
    return 0;
  }
  ll y = X - D * t;
  K -= t;
  if (K % 2 == 0) {
    cout << y << endl;
  }else {
    cout << D - y << endl;
  }

  return 0;
}

