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

  ll big = 1e18;
  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((U, dec=1), (V, dec=1), L)) [rkaLxgyU]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  auto L = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    ll v3; cin >> v3; L[i] = v3;
  }
  // @End [rkaLxgyU]
  auto func = [&](ll idx) -> ll {
    vector nbr(N, vector<pll>());
    REP(i, 0, M) {
      if (i == idx) continue;
      nbr[U[i]].emplace_back(V[i], L[i]);
      nbr[V[i]].emplace_back(U[i], L[i]);
    }
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[0] = 0;
    pque.emplace(0, 0);
    while (not pque.empty()) {
      auto [d, y] = pque.top(); pque.pop();
      if (dist[y] == d) {
        for (auto [z, len] : nbr[y]) {
          ll newd = d + len;
          if (newd < dist[z]) {
            dist[z] = newd;
            pque.emplace(newd, z);
          }
        }
      }
    }
    ll goal = (U[idx] == 0) ? V[idx] : U[idx];
    return L[idx] + dist[goal];
  };
  ll ans = big;
  REP(i, 0, M) {
    if (U[i] == 0 or V[i] == 0) ans = min(ans, func(i));
  }
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

