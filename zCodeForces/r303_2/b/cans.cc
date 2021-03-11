#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  ll n = s.size();
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (s[i] != t[i]) cnt++;
  }
  if (cnt % 2 == 1) {
    cout << "impossible\n";
    return 0;
  }
  ll p = 0;
  for (ll i = 0; i < n; i++) {
    if (p < cnt / 2 && s[i] != t[i]) {
      cout << t[i];
      p++;
    }else {
      cout << s[i];
    }
  }
  cout << endl;

  return 0;
}

