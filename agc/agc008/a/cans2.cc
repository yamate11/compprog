#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve(int x, int y) {
  if (y > 0) {
    if (x > y) return solve(-x, y) + 1;
    if (x >= 0) return y - x;
    if (x > -y) return solve(-x, y) + 1;
    return -y - x + 1;
  }else if (y == 0) {
    if (x < 0) return -x;
    return 1 + solve(-x, y);
  }else {
    if (x > -y) return solve(-x, y) + 1;
    if (x >= 0) return -y - x + 1;
    if (x > y) return solve(-x, y) + 1;
    return y - x;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  int x, y; cin >> x >> y;
  cout << solve(x, y) << endl;
  return 0;
}

