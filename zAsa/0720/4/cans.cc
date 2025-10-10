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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, X; cin >> N >> M >> X;
  vector fwd(2*N, vector<pll>());
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
  vector dist(2*N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : fwd[nd]) {
        ll new_d = d + len;
        if (new_d < dist[peer]) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll a = min(dist[N - 1], dist[N + N - 1]);
  cout << a << endl;

  return 0;
}

