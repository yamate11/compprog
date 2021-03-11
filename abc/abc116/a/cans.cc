#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve() {
  int x, y, z; cin >> x >> y >> z;
  if (x <= z && y <= z) {
    return x * y / 2;
  }else if (x <= y && z <= y) {
    return x * z / 2;
  }else if (y <= x && z <= x) {
    return y * z / 2;
  }else assert(false);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << solve() << endl;

  return 0;
}

