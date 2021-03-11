#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  using nbr_t = tuple<ll, ll, bool>;
  vector<vector<nbr_t>> nbr(N + 1);
  vector<bool> edir(M + 1);
  for (ll i = 1; i <= M; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].emplace_back(b, i, true);
    nbr[b].emplace_back(a, i, false);
  }
  vector<ll> C(N + 1);
  for (ll i = 1; i <= N; i++) cin >> C[i];
  vector<bool> visited(N + 1);
  auto dfs = [&](auto rF, ll nd) -> void {
    if (visited[nd]) return;
    visited[nd] = 1;
    for (auto [m, ei, fl] : nbr[nd]) {
      if (C[nd] > C[m]) {
        edir[ei] = fl;
      }else if (C[nd] < C[m]) {
        edir[ei] = !fl;
      }else {
        edir[ei] = fl;
        rF(rF, m);
      }
    }
  };
  for (ll i = 1; i <= N; i++) {
    dfs(dfs, i);
  }

  for (ll i = 1; i <= M; i++) {
    if (edir[i]) {
      cout << "->\n";
    }else {
      cout << "<-\n";
    }
  }

  return 0;
}

