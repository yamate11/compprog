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

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1) [a5bOj4Ou]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [a5bOj4Ou]
  // @InpMVec(K, ((P, dec=1), H)) [jvpOUkNo]
  auto P = vector(K, ll());
  auto H = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    ll v2; cin >> v2; H[i] = v2;
  }
  // @End [jvpOUkNo]

  vector<ll> health(N, -1LL);
  priority_queue<pll> pque;
  REP(k, 0, K) {
    pque.emplace(H[k], P[k]);
    health[P[k]] = H[k];
  }
  while (not pque.empty()) {
    auto [h, p] = pque.top(); pque.pop();
    if (health[p] > h) continue;
    if (h > 0) {
      for (ll q : nbr[p]) {
        if (health[q] < h - 1) {
          health[q] = h - 1;
          pque.emplace(h - 1, q);
        }
      }
    }
  }
  vector<ll> ans;
  REP(i, 0, N) {
    if (health[i] >= 0) ans.push_back(i);
  }
  cout << SIZE(ans) << "\n";
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, " ");

  return 0;
}
