#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x1, y1, r, x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
  ll b = x1 + r <= x3 &&
    x1 - r >= x2 &&
    y1 + r <= y3 &&
    y1 - r >= y2;
  cout << (b ? "NO\n" : "YES\n");
  auto in = [&](ll x, ll y) -> bool {
    return (x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r;
  };

  ll bb = in(x2,y2) && in(x2,y3) && in(x3,y2) && in(x3,y3);
  cout << (bb ? "NO\n" : "YES\n");

  return 0;
}

