#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int a1, a2, a3; cin >> a1 >> a2 >> a3;
  if (a1 + a2 + a3 >= 22) {
    cout << "bust\n";
  }else {
    cout << "win\n";
  }

  return 0;
}

