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
  ll p = -1, e = -1;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '.') p = i;
    if (s[i] == 'e') e = i;
  }
  string sa = s.substr(0, p);
  string sd = s.substr(p + 1, e - p - 1);
  string sb = s.substr(e + 1);

  /*
    ll a = stoi(sa);
    ll d = stoi(sd);
  */
  ll b = stoi(sb);
  
  ll r = b - (ll)sd.size();

  string ans = sa + sd.substr(0, b);
  if (r < 0) {
    if (b == 0 && sd == "0") {
    }else {
      ans += '.' + sd.substr(b);
    }
  }else if (r > 0) {
    for (ll i = 0; i < r; i++) {
      ans += '0';
    }
  }
  cout << ans << endl;

  return 0;
}

