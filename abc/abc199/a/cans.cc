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

  ll a, b, c; cin >> a >> b >> c;
  if (a*a + b*b < c*c) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

