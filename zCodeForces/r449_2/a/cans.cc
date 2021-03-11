#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  string s; cin >> s;
  for (ll i = 0; i < m; i++) {
    ll l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2; l--;
    for (ll j = l; j < r; j++) {
      if (s[j] == c1) s[j] = c2;
    }
  }
  cout << s << endl;


  return 0;
}

