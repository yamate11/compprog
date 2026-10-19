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
  // @InpMVec(M, ((U, dec=1), (V, dec=1), W)) [C2FMnx67]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [C2FMnx67]
  ll K; cin >> K;
  // @InpVec(K, E, dec=1) [gHyYdpT4]
  auto E = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; E[i] = v; }
  // @End [gHyYdpT4]
  
  vector<bool> e_ok(M, true);
  REP(i, 0, K) e_ok[E[i]] = false;

  vector nbr1(N, vector<pll>());
  vector nbr2(N, vector<pll>());
  REP(i, 0, M) {
    nbr1[U[i]].emplace_back(V[i], W[i]);
    nbr1[V[i]].emplace_back(U[i], W[i]);
    if (e_ok[i]) {
      nbr2[U[i]].emplace_back(V[i], W[i]);
      nbr2[V[i]].emplace_back(U[i], W[i]);
    }
  }
  auto f = [&](const auto& nbr) -> void {
    ll big = 1LL << 60;
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[0] = 0;
    pque.emplace(0, 0);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [peer, len] : nbr[nd]) {
          ll new_d = d + len;
          if (dist[peer] > new_d) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    ll ans = dist[N - 1];
    if (ans == big) ans = -1;
    cout << ans << "\n";
  };

  f(nbr1);
  f(nbr2);

  return 0;
}

