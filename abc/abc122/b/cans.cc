#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


bool foo(char c) {
  return c == 'A' || c == 'C' || c == 'G' || c == 'T';
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if (foo(S.at(i))) cnt += 1;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans << endl;

  return 0;
}

