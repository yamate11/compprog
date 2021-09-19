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
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll lim = llround(sqrt(N));
  vector<bool> heavy(N);
  vector<vector<ll>> heavy_nbr(N);
  for (ll u = 0; u < N; u++) {
    if ((ll)nbr[u].size() > lim) {
      heavy[u] = true;
      for (ll v : nbr[u]) heavy_nbr[v].push_back(u);
    }
  }
  using sta = pair<ll, ll>;
  vector<sta> rec(N);
  for (ll i = 0; i < N; i++) rec[i] = sta(i + 1, -1);
  vector<sta> distr(N);
  for (ll i = 0; i < N; i++) distr[i] = sta(0, -2);
  auto get_val = [&](ll x) -> ll {
    auto [v0, t0] = rec[x];
    for (ll y : heavy_nbr[x]) {
      auto [dv, dt] = distr[y];
      if (t0 < dt) {
        t0 = dt;
        v0 = dv;
      }
    }
    return v0;
  };
  for (ll t_cur = 0; t_cur < Q; t_cur++) {
    ll x; cin >> x; x--;
    ll v0 = get_val(x);
    if (heavy[x]) {
      distr[x] = sta(v0, t_cur);
    }else {
      for (ll y : nbr[x]) {
        rec[y] = sta(v0, t_cur);
      }
    }
    rec[x] = sta(v0, t_cur);
  }
  for (ll i = 0; i < N; i++) {
    cout << get_val(i) << " ";
  }

  return 0;
}

