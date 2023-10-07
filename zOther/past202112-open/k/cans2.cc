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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q, K; cin >> N >> M >> K >> Q;
  // @InpVec(K, A, dec=1) [AST1Rd0Y]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [AST1Rd0Y]
  // @InpNbrList(N, M, nbr, dec=1) [8tbdrU1w]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [8tbdrU1w]

  ll big = 1e18;
  auto dist = vector(K, vector(N, big));
  REP(k, 0, K) {
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[k][A[k]] = 0;
    pque.emplace(0, A[k]);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[k][nd] == d) {
        for (ll peer : nbr[nd]) {
          ll newD = d + 1;
          if (newD < dist[k][peer]) {
            dist[k][peer] = newD;
            pque.emplace(newD, peer);
          }
        }
      }
    }
  }

  REP(_q, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    ll ans = big;
    REP(i, 0, K) {
      updMin(ans, dist[i][s] + dist[i][t]);
    }
    cout << ans << "\n";
  }

  return 0;
}

