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

  ll N, M, K; cin >> N >> M >> K;
  // @InpMVec(M, ((U, dec=1), (V, dec=1), W)) [jITum1kf]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [jITum1kf]
  // @InpVec(K, C, dec=1) [2NnMuYfn]
  auto C = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [2NnMuYfn]
  vector<bool> record(M, false);
  REP(i, 0, K) record[C[i]] = true;
  vector nbr(N, vector<pll>());
  REP(i, 0, M) {
    ll w = record[i] ? W[i] * 2 : W[i];
    nbr[U[i]].emplace_back(V[i], w);
    nbr[V[i]].emplace_back(U[i], w);
  }
  ll big = 1e18;
  vector<ll> dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        ll new_d = d + len;
        if (new_d < dist[peer]) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  if (dist[N - 1] == big) {
    cout << -1 << endl;
  }else {
    cout << dist[N - 1] << endl;
  }


  return 0;
}

