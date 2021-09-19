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

  ll x; cin >> x;
  if (x < 40) {
    cout << 40 - x << endl;
  }else if (x < 70) {
    cout << 70 - x << endl;
  }else if (x < 90) {
    cout << 90 - x << endl;
  }else {
    cout << "expert" << endl;
  }

  return 0;
}

