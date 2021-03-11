#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int cc = 0;
  int minZ = 10;
  for (int i = 0; i < 5; i++) {
    int x; cin >> x;
    int y = 10 * ((x+9) / 10);
    cc += y;
    int z = x % 10;
    if (z < minZ && 0 < z) {
      minZ = z;
    }
  }
  if (minZ == 10) {
    cout << cc << endl;
    return 0;
  }
  cout << cc - 10 + minZ << endl;

  return 0;
}

