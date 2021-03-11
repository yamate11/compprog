#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H; cin >> H;
  ll cnt = 1;
  while (H > 0) {
    H >>= 1;
    cnt *= 2;
  }
  cout << cnt - 1 << endl;

  return 0;
}

