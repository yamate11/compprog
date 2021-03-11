#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<vector<pair<ll, ll>>> nbr(N);
  for (ll i = 0; i < N-1; i++) {
    ll x, y, c; cin >> x >> y >> c; x--; y--;
    nbr.at(x).emplace_back(y, c);
    nbr.at(y).emplace_back(x, c);
  }
  vector<ll> costRoot(N);
  unordered_map<ll, ll> numCR;
  auto dfs = [&](const auto& recF, ll n, ll parent, ll acc) -> void {
    costRoot.at(n) = acc;
    numCR[acc]++;
    for (auto q : nbr.at(n)) {
      ll m = q.first, cost = q.second;
      if (m == parent) continue;
      recF(recF, m, n, acc ^ cost);
    }
  };
  dfs(dfs, 0, -1, 0);
  if (X == 0) {
    ll tot = 0;
    for (auto p : numCR) {
      ll n = p.second;
      tot += n * (n-1) / 2;
    }
    cout << tot << endl;
  }else {
    ll tot = 0;
    for (ll i = 0; i < N; i++) {
      tot += numCR[X ^ costRoot.at(i)];
    }
    cout << tot / 2 << endl;
  }

  return 0;
}

