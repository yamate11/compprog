#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int A, B; cin >> A >> B;
  if (B % A == 0) cout << A + B << endl;
  else            cout << B - A << endl;
  return 0;
}

