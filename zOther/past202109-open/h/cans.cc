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

  ll N, X; cin >> N >> X;
  // @InpNbrList(N, N - 1, nbr, dec=1, read=C) [DRB8UlGy]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t() {}
    nbr_t(int nd_, ll C_) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [DRB8UlGy]
  ll big = 1e18;
  REP(i, 0, N) {
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    vector<ll> dist(N, big);
    dist[i] = 0;
    pque.emplace(0, i);
    while (not pque.empty()) {
      auto [d, n] = pque.top(); pque.pop();
      if (d == dist[n]) {
        if (d == X) {
          cout <<"Yes\n";
          return 0;
        }
        for (auto [m, c] : nbr[n]) {
          ll newD = d + c;
          if (newD < dist[m]) {
            dist[m] = newD;
            pque.emplace(newD, m);
          }
        }
      }
    }
  }
  cout << "No\n";
  

  return 0;
}

