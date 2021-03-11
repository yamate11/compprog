#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  ll szs = s.size();
  ll szt = t.size();

  vector<ll> pos1(szt), pos2(szt);
  ll j = 0;
  for (ll i = 0; i < szt; i++) {
    while (s[j] != t[i]) j++;
    pos1[i] = j;
    j++;
  }
  j = szs - 1;
  for (ll i = szt - 1; i >= 0; i--) {
    while (s[j] != t[i]) j--;
    pos2[i] = j;
    j--;
  }
  ll ans = max(pos2[0], szs - pos1[szt - 1] - 1);
  for (ll i = 0; i+1 < szt; i++) {
    ans = max(ans, pos2[i+1] - pos1[i] - 1);
  }
  cout << ans << endl;

  return 0;
}

