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

  ll N, M, K, T; cin >> N >> M >> K >> T;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [W5hJ3xXf]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [W5hJ3xXf]
  
  // @InpVec(K, A, dec=1) [0suUkEAX]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [0suUkEAX]

  ll big = 1e18;
  auto func = [&](ll start) -> vector<ll> {
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
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
    return dist;
  };

  auto dist0 = func(0);
  auto dist1 = func(N - 1);
  double ans = dist0[N - 1];
  REP(k, 0, K) {
    if (dist0[A[k]] == big) continue;
    ll n0 = llround(sqrt((double)dist1[A[k]] / T) - 1);
    double cur = 1e18;
    REP(n, max(0LL, n0 - 2), n0 + 3) {
      updMin(cur, (double)dist1[A[k]] / (1 + n) + n * T + dist0[A[k]]);
    }
    updMin(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

