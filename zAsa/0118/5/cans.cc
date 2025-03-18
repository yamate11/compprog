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
  // @InpNbrList(N, M, nbr, dec=1, read=L) [zzYJrICi]
  struct nbr_t {
    int nd;
    ll L;
    // nbr_t() {}
    nbr_t(int nd_ = int(), ll L_ = ll()) : nd(nd_), L(L_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll L; cin >> L;
    nbr[u].emplace_back(v, L);
    nbr[v].emplace_back(u, L);
  }
  // @End [zzYJrICi]

  ll big = 1e18;

  auto func = [&](ll p0) -> ll {
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[0] = 0;
    pque.emplace(0, 0);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [p, len] : nbr[nd]) {
          if (nd == 0 and p == p0) continue;
          ll new_d = d + len;
          if (new_d < dist[p]) {
            dist[p] = new_d;
            pque.emplace(new_d, p);
          }
        }
      }
    }
    return dist[p0];
  };


  ll ans = big;
  for (auto [peer, len] : nbr[0]) {
    ll x = func(peer);
    ans = min(ans, len + x);
  }
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

