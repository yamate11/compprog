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

  ll N; cin >> N;
  string s;
  while (N > 0) {
    if (N % 2 == 1) s += '1';
    else s += '0';
    N /= 2;
  }
  reverse(s.begin(), s.end());
  string ans;
  for (ll i = 0; i < (ll)s.size(); i++) {
    if (s[i] == '1') {
      if (i > 0) ans += 'B';
      ans += 'A';
    }else {
      ans += 'B';
    }
  }
  cout << ans << endl;
  return 0;
}

