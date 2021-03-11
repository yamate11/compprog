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
  int ans = 0;
  for (int i = 0; i < (int)S.size() / 2; i++) {
    if (S.at(i) != S.at(S.size() - 1 - i)) ans++;
  }
  cout << ans << endl;

  return 0;
}

