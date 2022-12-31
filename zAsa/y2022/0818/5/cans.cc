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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, read=c, dec=1, dir=True) [U4sxRr5f]
  struct fwd_t {
    int nd;
    ll c;
    fwd_t() {}
    fwd_t(int nd_, ll c_) : nd(nd_), c(c_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll c; cin >> c;
    fwd[u].emplace_back(v, c);
  }
  // @End [U4sxRr5f]
  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(start, 0, N) {
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start][start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [d, u] = pque.top(); pque.pop();
      if (dist[start][u] < d) continue;
      for (auto [v, c] : fwd[u]) {
        ll newD = d + c;
        if (newD < dist[start][v]) {
          dist[start][v] = newD;
          pque.emplace(newD, v);
        }
      }
    }
  }
  vector self(N, big);
  REP(i, 0, N) for (auto [j, c] : fwd[i]) if (i == j) updMin(self[i], c);
  REP(i, 0, N) {
    ll a = self[i];
    REP(j, 0, N) {
      if (j == i) continue;
      a = min(a, dist[i][j] + dist[j][i]);
    }
    cout << (a >= big ? -1 : a) << endl;
  }

  return 0;
}

