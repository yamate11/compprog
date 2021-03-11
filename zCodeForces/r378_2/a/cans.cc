#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto vowel = [&](char c) -> bool {
    return c == 'A'
      || c == 'E'
      || c == 'I'
      || c == 'O'
      || c == 'U'
      || c == 'Y'
      ;
  };

  string s; cin >> s;
  ll n = s.size();
  ll prev = -1;
  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    if (i == n || vowel(s[i])) {
      ans = max(ans, i - prev);
      prev = i;
    }
  }
  cout << ans << endl;

  return 0;
}

