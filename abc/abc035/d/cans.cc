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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

  ll N, M, T; cin >> N >> M >> T;
  // @InpVec(N, A) [sH9aESFV]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [sH9aESFV]

  // @InpNbrList(N, M, fwd, dir=True, bwd=bwd, dec=1, read=C) [THMpf67Q]
  struct fwd_t {
    int nd;
    ll C;
    // fwd_t() {}
    fwd_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  auto bwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    fwd[u].emplace_back(v, C);
    bwd[v].emplace_back(u, C);
  }
  // @End [THMpf67Q]

  ll big = 1e18;
  auto f = [&](const auto& nbr) {
    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[0] = 0;
    pque.emplace(0, 0);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [peer, t] : nbr[nd]) {
          ll new_d = d + t;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    return dist;
  };

  auto distF = f(fwd);
  auto distB = f(bwd);
  ll ans = 0;
  REP(i, 0, N) {
    ll t = distF[i] + distB[i];
    if (t < T) updMax(ans, (T - t) * A[i]);
  }
  cout << ans << endl;

  return 0;
}

