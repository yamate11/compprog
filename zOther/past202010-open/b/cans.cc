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

  ll X, Y; cin >> X >> Y;
  if (Y == 0) {
    cout << "ERROR\n";
    return 0;
  }
  ll x = (X * 100) / Y;
  ll p = x / 100;
  ll q = x % 100;
  cout << p << "." << setfill('0') << setw(2) << q << endl;
  

  return 0;
}

