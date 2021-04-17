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

  ll x, y, z; cin >> x >> y >> z;
  ll a = -1;
  if (y * z % x == 0) a = y * z / x - 1;
  else a = y * z / x;
  cout << a << endl;

  return 0;
}

