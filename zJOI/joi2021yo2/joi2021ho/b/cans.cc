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

  ll N, Q; cin >> N >> Q;
  vector<ll> X(N);
  for (ll i = 0; i < N; i++) cin >> X[i];
  using sta = pair<ll, ll>;
  ll big = 1e18;
  vector<sta> rec({{big, 0}, {big, N}});
  for (ll i = 1; i < N; i++) rec.emplace_back(X[i] - X[i-1], i);
  sort(rec.begin(), rec.end());
  vector<ll> bound({0, 0});
  ll pos = 0;
  ll sidx = 0;
  vector<ll> ans(N);

  auto op = [&](ll me, ll you, ll newbnd) -> void {
    if (newbnd <= bound[me]) return;
    bound[me] = newbnd;
    ll bnd = bound[0] + bound[1];
    ll p = upper_bound(rec.begin(), rec.end(), sta(bnd, -1)) - rec.begin();
    for (ll j = sidx; j < p; j++) {
      auto [v, i] = rec[j];
      ans[i-1+you] += bound[you];
      ans[i-1+me]  += v - bound[you];
    }
    sidx = p;
  };

  for (; Q > 0; Q--) {
    ll w; cin >> w;
    pos += w;
    op(0, 1, pos);
    op(1, 0, -pos);
  }
  for (ll j = sidx; j <= N; j++) {
    auto [v, i] = rec[j];
    if (i-1 >= 0) ans[i-1] += bound[0];
    if (i < N)    ans[i]   += bound[1];
  }
  for (ll i = 0; i < N; i++) cout << ans[i] << "\n";

  return 0;
}

