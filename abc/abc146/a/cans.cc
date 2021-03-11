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
  int ans = S == "SUN" ? 7 :
    S == "MON" ? 6 :
    S == "TUE" ? 5 :
    S == "WED" ? 4 :
    S == "THU" ? 3 :
    S == "FRI" ? 2 :
    S == "SAT" ? 1 : 0;

  cout << ans << endl;

  return 0;
}

