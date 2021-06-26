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

  string s; cin >> s;
  ll cnt = 0;
  for (ll i = 0; i < 4; i++) if (s[i] == '2') cnt++;
  cout << cnt << endl;

  return 0;
}

