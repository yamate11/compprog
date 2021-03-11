#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  if (H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }
  cout << (H*W + 1) / 2 << endl;

  return 0;
}

