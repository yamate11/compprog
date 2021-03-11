#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll tr(ll p) {
  if (p < 0) return -p;
  if (p > 8) return 16 - p;
  return p;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, Y; cin >> X >> Y; X--; Y--;
  string W; cin >> W;
  vector<string> C(9);
  for (ll i = 0; i < 9; i++) cin >> C.at(i);
  ll dx = 0;
  ll dy = 0;
  for (char z : W) {
    if (z == 'R') dx = 1;
    if (z == 'L') dx = -1;
    if (z == 'U') dy = -1;
    if (z == 'D') dy = 1;
  }
  for (ll i = 0; i < 4; i++) {
    cout << C.at(tr(Y)).at(tr(X));
    X += dx;
    Y += dy;
  }
  cout << endl;

  return 0;
}

