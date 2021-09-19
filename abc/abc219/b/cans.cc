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

  vector<string> S(3);
  string T;
  for (ll i = 0; i < 3; i++) cin >> S[i];
  cin >> T;
  for (ll i = 0; i < (ll)T.size(); i++) {
    ll x = T[i] - '1';
    cout << S[x];
  }
  cout << endl;

  return 0;
}

