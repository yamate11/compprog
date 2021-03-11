#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int X; cin >> X;
  if (X == 7 || X == 5 || X == 3) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }

  return 0;
}

