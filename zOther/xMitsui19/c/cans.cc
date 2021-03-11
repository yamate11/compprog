#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve() {
  int X; cin >> X;
  if (X >= 2000) return 1;
  int p = X / 100;
  int q = X % 100;
  if (q <= p * 5) return 1;
  else return 0;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << solve() << endl;

  return 0;
}

