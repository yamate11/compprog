#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int X, Y; cin >> X >> Y;
  if (X == 1 && Y == 1) {
    cout << 1000000 << endl;
    return 0;
  }
  auto f = [&](int p) {
    if (p == 1) return 300000;
    if (p == 2) return 200000;
    if (p == 3) return 100000;
    return 0;
  };
  int ans = f(X) + f(Y);
  cout << ans << endl;

  return 0;
}

