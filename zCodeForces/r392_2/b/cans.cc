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
  string col = "RBYG";
  vector<ll> cmod(4);
  for (ll i = 0; i < n; i++) {
    if (s[i] == '!') continue;
    for (ll j = 0; j < 4; j++) {
      if (s[i] == col[j]) cmod[i % 4] = j;
    }
  }
  vector<ll> ans(4);
  for (ll i = 0; i < n; i++) {
    if (s[i] == '!') {
      ll c = cmod[i % 4];
      ans[c]++;
    }
  }
  for (ll i = 0; i < 4; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

