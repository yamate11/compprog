#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  vector<vector<ll>> c(3, vector<ll>(3));
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> c.at(i).at(j);
    }
  }
  for (ll i = 0; i < 2; i++) {
    ll p = c.at(i+1).at(0) - c.at(i).at(0);
    for (ll j = 1; j < 3; j++) {
      if (c.at(i+1).at(j) - c.at(i).at(j) != p) return false;
    }
  }
  for (ll i = 0; i < 2; i++) {
    ll p = c.at(0).at(i+1) - c.at(0).at(i);
    for (ll j = 1; j < 3; j++) {
      if (c.at(j).at(i+1) - c.at(j).at(i) != p) return false;
    }
  }
  return true;

}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Yes\n" : "No\n");
  return 0;
}

