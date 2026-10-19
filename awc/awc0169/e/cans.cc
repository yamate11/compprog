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
  // @InpVec(N, P) [NnlYZQji]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [NnlYZQji]
  // @InpMVec(M, ((U, dec=1), (V, dec=1), W)) [zYeCepXn]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [zYeCepXn]
  REP(i, 0, N) P[i] *= 2;
  REP(i, 0, M) W[i] *= 2;

  vector nbr(N, vector<pll>{});
  REP(i, 0, M) {
    nbr[U[i]].emplace_back(V[i], W[i]);
    nbr[V[i]].emplace_back(U[i], W[i]);
  }

  ll big = 1LL << 60;
  vector<ll> dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, w] : nbr[nd]) {
        ll len = w - (P[nd] + P[peer]) / 2;
        if (len < 0) {
          cout << "-inf\n";
          return 0;
        }
        ll new_d = d + len;
        if (dist[peer] > new_d) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll a = dist[N - 1] - (P[0] + P[N - 1]) / 2;
  assert(a < big and a % 2 == 0);
  cout << a / 2 << "\n";
  return 0;
}

