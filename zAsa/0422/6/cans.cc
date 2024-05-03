#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector fwd(N, vector<pll>());
  vector bwd(N, vector<pll>());
  REP(i, 0, M) {
    ll s, t; cin >> s >> t; s--; t--;
    fwd[s].emplace_back(t, i);
    bwd[t].emplace_back(s, i);
  }
  ll big = 1e10;
  ll dist_all = -1;
  vector bedge(N, -1LL);
  vector bnd(N, -1LL);
  {
    vector dist(N, big);
    dist[0] = 0;
    queue<ll> que;
    que.push(0);
    while (not que.empty()) {
      ll nd = que.front(); que.pop();
      for (auto [peer, idx] : fwd[nd]) {
        if (dist[peer] == big) {
          dist[peer] = dist[nd] + 1;
          bnd[peer] = nd;
          bedge[peer] = idx;
          que.push(peer);
        }
      }
    }
    dist_all = dist[N - 1];
  }
  vector<ll> ans(M, -2LL);
  if (dist_all == big) {
    REP(e, 0, M) ans[e] = big;
  }else {
    vector<ll> route;
    ll n = N - 1;
    while (n > 0) {
      route.push_back(bedge[n]);
      n = bnd[n];
    }
    for (ll e : route) {
      vector dist0(N, big);
      dist0[0] = 0;
      queue<ll> que0;
      que0.push(0);
      while (not que0.empty()) {
        ll nd = que0.front(); que0.pop();
        for (auto [peer, idx] : fwd[nd]) {
          if (idx == e) continue;
          if (dist0[peer] == big) {
            dist0[peer] = dist0[nd] + 1;
            que0.push(peer);
          }
        }
      }
      ans[e] = dist0[N - 1];
    }
    REP(e, 0, M) {
      if (ans[e] == -2) ans[e] = dist_all;
    }
  }
  REPOUT(e, 0, M, ans[e] == big ? -1 : ans[e], "\n");

  return 0;
}

