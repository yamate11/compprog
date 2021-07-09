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

  string S; cin >> S;
  for (ll i = 0; i <= 2; i++) {
    if (S[i] == S[i+1] && S[i] == S[i+2]) {
      cout << S[i] << endl;
      return 0;
    }
  }
  cout << "draw" << endl;

  return 0;
}

