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
  // @InpNbrList(N, M, nbr, dec=1, read=C, idx=idx) [3BGy0xfZ]
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
  // @End [3BGy0xfZ]

  const ll big = 1e18;
  vector<bool> used(M);
  REP(root, 0, N) {
    using sta = tuple<ll, ll, ll>;
    priority_queue<sta, vector<sta>, greater<sta>> pque;
    vector<ll> dist(N, big);
    pque.emplace(0, root, -1);
    dist[root] = 0;
    while (not pque.empty()) {
      auto [d, nd, eidx] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        if (eidx >= 0) used[eidx] = true;
        for (auto [p, cost, i] : nbr[nd]) {
          if (d + cost < dist[p]) {
            dist[p] = d + cost;
            pque.emplace(d + cost, p, i);
          }
        }
      }
    }
  }
  ll cnt = 0;
  REP(i, 0, M) if (not used[i]) cnt++;
  cout << cnt << endl;

  return 0;
}

