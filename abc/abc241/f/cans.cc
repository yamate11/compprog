#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  ll sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy; sx--; sy--; gx--; gy--;
  map<ll, vector<ll>> ys, xs;
  REP(i, N) {
    ll x, y; cin >> x >> y; x--; y--;
    ys[x].push_back(y);
    xs[y].push_back(x);
  }
  for (auto& [x, vs] : ys) sort(ALL(vs));
  for (auto& [y, vs] : xs) sort(ALL(vs));
  ll lim = 1e9;
  auto enc = [&](ll x, ll y) -> ll { return (lim + 1) * x + y; };
  map<ll, ll> dist;
  using sta = pair<ll, ll>;
  queue<sta> que;
  que.emplace(sx, sy);
  dist[enc(sx, sy)] = 0;
  ll ans = -1;
  while (ans < 0 and not que.empty()) {
    auto [x, y] = que.front(); que.pop();
    ll dist0 = dist[enc(x, y)];
    auto dotry = [&](ll x1, ll y1) -> void {
      if (dist.find(enc(x1, y1)) == dist.end()) {
        dist[enc(x1, y1)] = dist0 + 1;
        if (x1 == gx and y1 == gy) ans = dist0 + 1;
        que.emplace(x1, y1);
      }
    };
    if (not ys[x].empty()) {
      ll j0 = lower_bound(ALL(ys[x]), y) - ys[x].begin();
      if (j0 < SIZE(ys[x])) dotry(x, ys[x][j0] - 1);
      if (j0 - 1 >= 0)      dotry(x, ys[x][j0 - 1] + 1);
    }
    if (not xs[y].empty()) {
      ll i0 = lower_bound(ALL(xs[y]), x) - xs[y].begin();
      if (i0 < SIZE(xs[y])) dotry(xs[y][i0] - 1, y);
      if (i0 - 1 >= 0)      dotry(xs[y][i0 - 1] + 1, y);
    }
  }
  cout << ans << endl;

  return 0;
}

