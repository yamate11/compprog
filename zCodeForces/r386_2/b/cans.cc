#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  string s; cin >> s;
  string t(n, ' ');
  if (n % 2 == 1) {
    t[n/2] = s[0];
    for (ll i = 0; i < n / 2; i++) {
      t[n/2 - (i + 1)] = s[1 + 2*i];
      t[n/2 + (i + 1)] = s[1 + 2*i + 1];
    }
  }else {
    for (ll i = 0; i < n / 2; i++) {
      t[n/2 - 1 - i] = s[2*i];
      t[n/2 + i] = s[2*i + 1];
    }
  }
  cout << t << endl;

  return 0;
}

