#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k; cin >> n >> m >> k;
  using pt_t = pair<ll, ll>;
  map<pt_t, int> pt_mp;
  vector<vector<ll>> row(n + 1), col(m + 1);
  for (ll i = 0; i < k; i++) {
    ll r, c; cin >> r >> c;
    pt_mp[pt_t(r, c)] = 1;
    row[r].push_back(c);
    col[c].push_back(r);
  }
  // abstract point: row..(r, -1) col ..(-1, c)
  using deq_t = pair<pt_t, ll>;
  deque<deq_t> deq;
  deq.emplace_back(pt_t(1, 1), 0);
  map<pt_t, ll> dist;
  dist[pt_t(1, 1)] = 0;

  auto get_dist =
    [&](const pt_t& p) -> ll {
      if (auto it = dist.find(p); it == dist.end()) return 1e18;
      else return it->second;
    };

  auto put =
    [&](const pt_t& p, ll d, ll dd) -> void {
      ll dis = d + dd;
      if (get_dist(p) > dis) {
        dist[p] = dis;
        if (dd == 0) deq.emplace_front(p, dis);
        else         deq.emplace_back(p, dis);
      }
    };

  while (!deq.empty()) {
    auto [pt, d] = deq.front(); deq.pop_front();
    auto [r, c] = pt;
    if ((r == n && c == -1) || (r == -1 && c == m) || (r == n && c == m)) {
      cout << d << endl;
      return 0;
    }
    if (c == -1) {
      for (ll rr = max(1LL, r - 1); rr <= min(n, r + 1); rr++) {
        for (ll ic : row[rr]) {
          put(pt_t(rr, ic), d, 0);
        }
      }
    }else if (r == -1) {
      for (ll cc = max(1LL, c - 1); cc <= min(m, c + 1); cc++) {
        for (ll ir : col[cc]) {
          put(pt_t(ir, cc), d, 0);
        }
      }
    }else {
      vector<pt_t> dirs({{-1,0},{1,0},{0,-1},{0,1}});
      for (auto [dr, dc] : dirs) {
        pt_t p(r + dr, c + dc);
        if (pt_mp.find(p) != pt_mp.end()) {
          put(p, d, 0);
        }
      }
      for (ll rr = max(1LL, r - 1); rr <= min(n, r + 1); rr++) {
        put(pt_t(rr, -1), d, 1);
      }
      for (ll cc = max(1LL, c - 1); cc <= min(m, c + 1); cc++) {
        put(pt_t(-1, cc), d, 1);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

