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
  if (n == 0) {
    cout << "a" << endl;
    return 0;
  }
  vector<ll> tri;
  for (ll i = 0; true; i++) {
    ll x = i * (i + 1) / 2;
    tri.push_back(x);
    if (x > n) break;
  }
  vector<ll> vec;
  while (n > 0) {
    ll i = upper_bound(tri.begin(), tri.end(), n) - tri.begin() - 1;
    vec.push_back(i + 1);
    n -= tri[i];
  }
  string ans;
  char c = 'a';
  for (ll t : vec) {
    string s(t, c);
    ans += s;
    c++;
  }
  cout << ans << endl;

  return 0;
}

