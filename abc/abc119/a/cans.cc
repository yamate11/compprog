#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  int m = (S.at(5) - '0') * 10 + (S.at(6) - '0');
  cout << ((m <= 4) ? "Heisei" : "TBD") << endl;

  return 0;
}

