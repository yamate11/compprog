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

  ll N, M, X; cin >> N >> M >> X;
  vector fwd(N * 2, vector<pll>());
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    fwd[u].emplace_back(v, 1);
    fwd[N + v].emplace_back(N + u, 1);
  }
  REP(i, 0, N) {
    fwd[i].emplace_back(N + i, X);
    fwd[N + i].emplace_back(i, X);
  }
  ll big = 1e18;
  vector dist(N * 2, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, x] = pque.top(); pque.pop();
    if (d == dist[x]) {
      if (x == N - 1 or x == 2*N - 1) {
        cout << d << endl;
        return 0;
      }
      for (auto [y, cost] : fwd[x]) {
        ll new_d = d + cost;
        if (new_d < dist[y]) {
          dist[y] = new_d;
          pque.emplace(new_d, y);
        }
      }
    }
  }
  assert(0);

  return 0;
}

