#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  char S; cin >> S;
  char T; cin >> T;
  if (S == 'Y') cout << (char)(T + ('A' - 'a')) << endl;
  else cout << T << endl;

  return 0;
}

