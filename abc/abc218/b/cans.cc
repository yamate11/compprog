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

  vector<ll> P(26);
  for (ll i = 0; i < 26; i++) cin >> P[i];
  for (ll i = 0; i < 26; i++) {
    cout << (char)('a' + P[i] - 1);
  }
  cout << endl;

  return 0;
}

