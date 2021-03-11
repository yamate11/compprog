#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, q, s; cin >> n >> q >> s; s--;
  ll rr = 1, pp = 2;
  while (pp < n) {
    rr++;
    pp *= 2;
  }
  vector<ll> vec(3 * pp);
  using sta = pair<ll, ll>;
  vector<vector<sta>> nbr(3 * pp);
  for (ll i = 1; i < pp; i++) {
    nbr[i].emplace_back(2*i,     0);
    nbr[i].emplace_back(2*i + 1, 0);
    if (i < pp / 2) {
      nbr[2*pp + 2*i    ].emplace_back(2*pp + i, 0);
      nbr[2*pp + 2*i + 1].emplace_back(2*pp + i, 0);
    }else {
      nbr[2*i    ].emplace_back(2*pp + i, 0);
      nbr[2*i + 1].emplace_back(2*pp + i, 0);
    }
  }
  auto nodes = [&](ll tp, ll l, ll r) -> vector<ll> {
    vector<ll> ret;
    auto sub = [&](auto rF, ll lb, ll rb, ll idx) -> void {
      if (rb <= l || r <= lb) return;
      else if (l <= lb && rb <= r) {
	if (tp == 2 || rb == lb + 1) {
	  ret.push_back(idx);
	}else {
	  ret.push_back(2 * pp + idx);
	}
      }else {
	ll mid = (lb + rb) / 2;
	rF(rF, lb, mid, 2*idx);
	rF(rF, mid, rb, 2*idx + 1);
      }
    };
    sub(sub, 0, pp, 1);
    return ret;
  };

  for (ll i = 0; i < q; i++) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll v, u, w; cin >> v >> u >> w; v--; u--;
      nbr[pp + v].emplace_back(pp + u, w);
    }else {
      ll v, l, r, w; cin >> v >> l >> r >> w; v--; l--;
      auto ns = nodes(tp, l, r);
      if (tp == 2) {
	for (ll x : ns) nbr[pp + v].emplace_back(x, w);
      }else if (tp == 3) {
	for (ll x : ns) nbr[x].emplace_back(pp + v, w);
      }
    }
  }

  vector<ll> dist(3 * pp, LLONG_MAX);
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  pque.emplace(0, pp + s);
  dist[pp + s] = 0;
  while (!pque.empty()) {
    auto [d, x] = pque.top(); pque.pop();
    if (dist[x] < d) continue;
    for (auto [y, dd] : nbr[x]) {
      if (d + dd >= dist[y]) continue;
      dist[y] = d + dd;
      pque.emplace(d + dd, y);
    }
  }
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    ll x = dist[pp + i];
    if (x == LLONG_MAX) x = -1;
    cout << x;
  }
  cout << endl;

  return 0;
}

