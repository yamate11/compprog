#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, p; cin >> n >> p;
  vector<ll> vec(p);
  string s; cin >> s;
  for (ll i = 0 ; i < n; i++) {
    ll t = s[i] == '0' ? 1 : s[i] == '1' ? 2 : 4;
    vec[i % p] |= t;
  }
  bool succ = false;
  for (ll i = 0; i < p; i++) {
    if (p + i >= n) continue;
    if (vec[i] == 1 || vec[i] == 2) continue;
    if ((vec[i] & 3) == 3) {
      succ = true;
      break;
    }
    if (vec[i] == 4) {
      s[i] = '0';
      s[p + i] = '1';
      succ = true;
      break;
    }
    if (vec[i] == 5) {
      succ = true;
      for (ll j = i; true; j += p) {
        if (s[j] == '.') {
          s[j] = '1';
          break;
        }
      }
    }
    if (vec[i] == 6) {
      succ = true;
      for (ll j = i; true; j += p) {
        if (s[j] == '.') {
          s[j] = '0';
          break;
        }
      }
    }
  }
  if (succ) {
    for (ll i = 0; i < n; i++) {
      if (s[i] == '.') s[i] = '0';
    }
    cout << s << endl;
  }else {
    cout << "No\n";
  }

  return 0;
}

