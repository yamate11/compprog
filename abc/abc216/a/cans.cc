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

  double q; cin >> q;
  ll p = llround(q * 10);
  ll x = p / 10;
  ll y = p % 10;
  if (y <= 2) {
    cout << x << "-" << endl;
  }else if (y <= 6) {
    cout << x << endl;
  }else {
    cout << x << "+" << endl;
  }

  return 0;
}

