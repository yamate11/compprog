#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X; cin >> X;
  for (ll i = 1; i <= 360; i++) {
    if ((i * X) % 360 == 0) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

