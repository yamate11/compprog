#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, ll m, auto& vec) -> ll {
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
      if (vec[i][m-1] == 'R') cnt++;
    }
    for (ll i = 0; i < m; i++) {
      if (vec[n-1][i] == 'D') cnt++;
    }
    return cnt;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, m; cin >> n >> m;
    vector<string> vec;
    for (ll i = 0; i < n; i++) {
      string s; cin >> s;
      vec.push_back(s);
    }
    cout << solve(n, m, vec) << "\n";
  }

  return 0;
}

