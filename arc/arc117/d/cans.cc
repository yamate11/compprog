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

  ll N; cin >> N;
  auto nbr = vector(N + 1, vector<ll>());
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  vector<ll> far(N + 1);
  using sta = pair<ll, ll>;
  auto dfs = [&](auto rF, ll nd, ll pt) -> sta {
    ll vm = 0;
    ll farest = nd;
    far[nd] = -1;
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      auto [f, v] = rF(rF, c, nd);
      v++;
      if (v > vm) {
        vm = v;
        farest = f;
        far[nd] = c;
      }
    }
    return {farest, vm};
  };
  auto [x1, _a] = dfs(dfs, 1, -1);
  dfs(dfs, x1, -1);
  vector<ll> lab(N + 1);
  ll seq = 0;
  auto dfs2 = [&](auto rF, ll nd, ll pt) -> void {
    seq++;
    lab[nd] = seq;
    for (ll c : nbr[nd]) {
      if (c == pt || c == far[nd]) continue;
      rF(rF, c, nd);
    }
    if (far[nd] >= 0) {
      rF(rF, far[nd], nd);
    }
    seq++;
  };
  dfs2(dfs2, x1, -1);

  for (ll i = 1; i <= N; i++) {
    cout << lab[i] << " ";
  }
  cout << endl;

  return 0;
}

