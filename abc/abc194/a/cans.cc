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

  ll A, B; cin >> A >> B;
  ll C = A + B;
  ll ans = -1;
  if (C >= 15 && B >= 8) ans = 1;
  else if (C >= 10 && B >= 3) ans = 2;
  else if (C >= 3) ans = 3;
  else ans = 4;
  cout << ans << endl;

  return 0;
}

