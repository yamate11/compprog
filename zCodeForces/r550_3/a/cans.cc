#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    string s; cin >> s;
    sort(s.begin(), s.end());
    ll n = s.size();
    for (ll i = 1; i < n; i++) {
      if (s[i] != s[i-1] + 1) return false;
    }
    return true;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

