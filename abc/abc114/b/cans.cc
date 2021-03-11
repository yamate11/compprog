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
  int diff = 10000;
  for (int i = 0; i+2 < (int)S.size(); i++) {
    int x = (S.at(i) - '0') * 100
      + (S.at(i+1) - '0') * 10 + (S.at(i+2) - '0');
    diff = min(diff, abs(x - 753));
  }
  cout << diff << endl;

  return 0;
}

