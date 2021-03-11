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
  for (ll i = 1; i < n - 1; i++) {
    vector<ll> vec(128);
    vec[s[i-1]] = 1;
    vec[s[i]] = 1;
    vec[s[i+1]] = 1;
    if (vec['A'] + vec['B'] + vec['C'] == 3) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;

}

