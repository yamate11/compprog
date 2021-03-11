#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, m; cin >> n >> m;

    auto round = [&](ll i, ll j) -> void {
      cout << "YES\n";
      bool first = true;
      for (ll cnt = 0; cnt < m + 1; cnt++) {
        if (first) first = false;
        else cout << " ";
        if (cnt % 2 == 0) cout << i;
        else cout << j;
      }
      cout << "\n";
      return;
    };

    vector<string> edge(n);
    for (ll i = 0; i < n; i++) cin >> edge[i];
    if (m == 1) {
      round(1, 2);
      return;
    }
    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        if (edge[i][j] == edge[j][i]) {
          round(i + 1, j + 1);
          return;
        }
      }
    }
    if (n == 2) {
      if (m % 2 == 0) {
        cout << "NO\n";
        return;
      }
      round(1, 2);
      return;
    }
    ll i, j, k;
    if (edge[0][1] == edge[1][2]) {
      i = 2; j = 1; k = 3;
    }else if (edge[1][2] == edge[2][0]) {
      i = 3; j = 2; k = 1;
    }else {
      i = 1; j = 3; k = 2;
    }
    if (m == 2) {
      cout << "YES\n" << j << " " << i << " " << k << "\n";
      return;
    }
    if (m % 2 == 1) {
      round(1, 2);
      return;
    }
    vector<ll> vec;
    if (m % 4 == 0) {
      vec.push_back(i);
      for (ll p = 0; p < m / 4; p++) {
        vec.push_back(j);
        vec.push_back(i);
        vec.push_back(k);
        vec.push_back(i);
      }
    }else if (m % 4 == 2) {
      vec.push_back(j);
      vec.push_back(i);
      vec.push_back(j);
      vec.push_back(i);
      for (ll p = 0; p < (m - 6) / 4; p++) {
        vec.push_back(j);
        vec.push_back(i);
        vec.push_back(k);
        vec.push_back(i);
      }
      vec.push_back(k);
      vec.push_back(i);
      vec.push_back(k);
    }
    cout << "YES\n";
    for (ll t = 0; t < (ll)vec.size(); t++) {
      if (t > 0) cout << " ";
      cout << vec[t];
    }
    cout << "\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

