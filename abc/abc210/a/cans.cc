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

  ll n, a, x, y; cin >> n >> a >> x >> y;
  if (n <= a) {
    cout << n * x << endl;
  }else {
    cout << x * a + y * (n - a) << endl;
  }

  return 0;
}

