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

  ll N, A, B, C; cin >> N >> A >> B >> C;
  // @InpGrid(N, N, D) [WvEQqbv9]
  auto D = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; D[i][j] = v; }
  // @End [WvEQqbv9]

  ll big = 1e18;
  auto func = [&](ll mode, ll start) -> vector<ll> {
    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (ll peer = 0; peer < N; peer++) {
          if (peer == nd) continue;
          ll dd;
          if (mode == 1) {
            dd = D[nd][peer] * A;
          }else if (mode == 2) {
            dd = D[nd][peer] * B + C;
          }else assert(0);
          ll newD = dist[nd] + dd;
          if (newD < dist[peer]) {
            dist[peer] = newD;
            pque.emplace(newD, peer);
          }
        }
      }
    }
    return dist;
  };

  auto vec1 = func(1, 0);
  auto vec2 = func(2, N - 1);
  ll ans = big;
  REP(i, 0, N) ans = min(ans, vec1[i] + vec2[i]);
  cout << ans << endl;

  return 0;
}

