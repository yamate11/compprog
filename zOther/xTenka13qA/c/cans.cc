#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve(ll n, ll m) {
  vector<vector<char>> brd(n, vector<char>(m));
  ll cnt = 0;
  auto dfs = [&](const auto& rF, ll r, ll c) -> void {
    if (c == m) { return rF(rF, r+1, 0); }
    if (r == n) {
      cnt++;
      return;
    }
    auto placeable = [&](ll t) -> bool {
      for (ll y = r-1; y >= 0 && y >= r-t; y--) {
	if (brd.at(y).at(c) == t) return false;
      }
      for (ll x = c-1; x >= 0 && x >= c-t; x--) {
	if (brd.at(r).at(x) == t) return false;
      }
      return true;
    };
    for (ll t = 1; t <= 3; t++) {
      if (placeable(t)) {
	brd.at(r).at(c) = t;
	rF(rF, r, c+1);
      }
    }
  };
  dfs(dfs, 0, 0);
  return cnt;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  if (N >= 12) N = 12 + (N % 4);
  if (M >= 12) M = 12 + (M % 4);
  cout << solve(N, M) << endl;
  return 0;
}

