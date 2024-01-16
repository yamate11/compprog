#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C, idx=idx) [xi5ZI3pA]
  struct nbr_t {
    int nd;
    ll C;
    int idx;
    nbr_t() {}
    nbr_t(int nd_, ll C_) : nd(nd_), C(C_) {}
    nbr_t(int nd_, ll C_, int idx_) : nd(nd_), C(C_), idx(idx_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C, i);
    nbr[v].emplace_back(u, C, i);
  }
  // @End [xi5ZI3pA]
  
  ll big = 1e18;
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  vector<ll> dist(N, big);
  vector<ll> route(N);
  pque.emplace(0, 0, -1);
  dist[0] = 0;
  while (not pque.empty()) {
    auto [d, nd, ii] = pque.top(); pque.pop();
    if (dist[nd] != d) continue;
    route[nd] = ii;
    for (auto [peer, len, ridx] : nbr[nd]) {
      ll newD = d + len;
      if (newD < dist[peer]) {
        dist[peer] = newD;
        pque.emplace(newD, peer, ridx);
      }
    }
  }
  REPOUT(i, 1, N, route[i] + 1, " ");

  return 0;
}

