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
  // @InpMVec(M, ((L, dec=1), (R, dec=1), C)) [Xf0nkyyb]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 1; R[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [Xf0nkyyb]

  vector nbr(N, vector<pll>());
  REP(i, 0, M) nbr[L[i]].emplace_back(R[i], C[i]);
  REP(i, 1, N) nbr[i].emplace_back(i - 1, 0);
  ll big = 1e18;
  vector<ll> dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, cost] : nbr[nd]) {
        ll new_dist = d + cost;
        if (new_dist < dist[peer]) {
          dist[peer] = new_dist;
          pque.emplace(new_dist, peer);
        }
      }
    }
  }
  cout << (dist[N - 1] == big ? -1 : dist[N - 1]) << endl;

  return 0;
}

