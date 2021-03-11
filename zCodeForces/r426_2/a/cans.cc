#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  char c1, c2; cin >> c1 >> c2;
  ll t; cin >> t;
  map<char,ll> mp;
  mp['^'] = 0;
  mp['>'] = 1;
  mp['v'] = 2;
  mp['<'] = 3;
  ll x1 = mp[c1];
  ll x2 = mp[c2];
  ll n; cin >> n;
  ll b1 = false;
  ll b2 = false;
  if ((x1 + t) % 4 == x2) b1 = true;
  ll y = (x1 - t) % 4;
  if (y < 0) y += 4;
  if (y == x2) b2 = true;
  string ans;
  if (b1 && !b2) ans = "cw";
  else if (!b1 && b2) ans = "ccw";
  else if (b1 && b2) ans = "undefined";
  else assert(0);
  cout << ans << endl;


  return 0;
}

