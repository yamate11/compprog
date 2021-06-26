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
  ll ans = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '1') ans++;
  }
  cout << ans << endl;
  return 0;
}

