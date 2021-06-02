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

  if (a == b) {
    cout << c << "\n";
  }else if (b == c) {
    cout << a << "\n";
  }else if (c == a) {
    cout << b << "\n";
  }else {
    cout << 0 << "\n";
  }

  return 0;
}

