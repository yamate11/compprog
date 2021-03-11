#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double L, X, Y, S, D; cin >> L >> X >> Y >> S >> D;

  double rev = 1e12;
  if (Y > X) {
    double rlen = S - D;
    if (rlen < 0) rlen += L;
    rev = rlen / (Y - X);
  }
  double len = D - S;
  if (len < 0) len += L;
  double ord = len / (X + Y);
  cout << min(ord, rev) << endl;

  return 0;
}

