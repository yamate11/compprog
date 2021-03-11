#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll X; cin >> X;
    if (X < 600) return 8;
    if (X < 800) return 7;
    if (X < 1000) return 6;
    if (X < 1200) return 5;
    if (X < 1400) return 4;
    if (X < 1600) return 3;
    if (X < 1800) return 2;
    return 1;
  };
  cout << solve() << endl;

  return 0;
}

