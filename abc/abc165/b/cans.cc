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
  ll t = 0;
  ll cur = 100;
  while (true) {
    t += 1;
    cur += cur / 100;
    if (cur >= X) {
      cout << t << endl;
      return 0;
    }
  }

  return 0;
}

