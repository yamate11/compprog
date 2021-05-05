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
  ll cnt = 0;
  for (ll i = 0; i <= 8; i++) {
    if (S.substr(i, 4) == "ZONe") cnt++;
  }
  cout << cnt << endl;

  return 0;
}

