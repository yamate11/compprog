#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll n = s.size();
  ll cnt = 0;
  for (ll i = 0; i < n / 2; i++) {
    if (s[i] != s[n-1 - i]) cnt++;
  }
  if (n % 2 == 0) {
    if (cnt == 1) cout << "YES\n";
    else cout << "NO\n";
  }else {
    if (cnt <= 1) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}

