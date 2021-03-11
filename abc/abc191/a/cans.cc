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

  ll v, t, s, d; cin >> v >> t >> s >> d;
  if (v * t <= d && d <= v * s) {
    cout << "No\n";
  }else {
    cout << "Yes\n";
  }

  return 0;
}

