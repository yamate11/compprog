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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpVec(N, C) [MjM8K0gh]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
    // @End [MjM8K0gh]
    // @InpGrid(N, M, A) [Eu8Ikj2q]
    auto A = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
    // @End [Eu8Ikj2q]

    auto enc_o = [&](ll i) -> ll { return i; };
    auto enc_v = [&](ll m, ll i) -> ll { return (m + 1) * N + i; };
    vector nbr(N + N * M, vector<pll>());
    REP(i, 0, N) {
      REP(m, 0, M) {
        nbr[enc_o(i)].emplace_back(enc_v(m, i), 0);
        nbr[enc_v(m, i)].emplace_back(enc_o(i), C[i]);
      }
    }
    REP(m, 0, M) {
      vector ord(N, 0LL); iota(ALL(ord), 0);
      sort(ALL(ord), [&](ll i, ll j) -> bool { return A[i][m] < A[j][m]; });
      REP(jj, 0, N - 1) {
        ll j = ord[jj];
        ll k = ord[jj + 1];
        nbr[enc_v(m, j)].emplace_back(enc_v(m, k), 0);
        nbr[enc_v(m, k)].emplace_back(enc_v(m, j), A[k][m] - A[j][m]);
      }
    }
    
    ll big = 1e18;
    vector dist(N + N * M, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[enc_o(0)] = 0;
    pque.emplace(0, enc_o(0));
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [peer, dd] : nbr[nd]) {
          ll new_d = d + dd;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    cout << dist[enc_o(N - 1)] << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

