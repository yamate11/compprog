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
  string s, t; cin >> s >> t;
  vector<ll> vec(n);
  ll carry = 0;
  for (ll i = n-1; i >= 0; i--) {
    ll p = carry + s[i] - 'a' + t[i] - 'a';
    vec[i] = p % 26;
    carry = p / 26;
  }
  for (ll i = 0; i < n; i++) {
    ll p = carry * 26 + vec[i];
    carry = p % 2;
    ll q = p / 2;
    cout << (char)('a' + q);
  }
  cout << endl;

  return 0;
}

