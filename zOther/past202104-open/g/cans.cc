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

  ll N, M, Q; cin >> N >> M >> Q;
  using sta = pair<ll, ll>;
  vector nbr(N, vector<sta>());
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    nbr[a].emplace_back(c, b);
    nbr[b].emplace_back(c, a);
  }
  set<sta> pending;
  vector<bool> visited(N);
  for (sta& s : nbr[0]) pending.insert(s);
  visited[0] = true;
  ll cnt = 1;
  for (ll q = 0; q < Q; q++) {
    ll x; cin >> x;
    vector<ll> tmp;
    for (auto it = pending.begin(); it != pending.end(); ) {
      auto [c, a] = *it;
      if (c > x) break;
      if (! visited[a]) {
        visited[a] = true;
        cnt++;
        tmp.push_back(a);
      }
      it = pending.erase(it);
    }
    cout << cnt << "\n";
    for (ll a : tmp) {
      for (sta& s : nbr[a]) pending.insert(s);
    }
  }

  return 0;
}

