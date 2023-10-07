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

  ll N, M, Q, K; cin >> N >> M >> Q >> K;
  vector<ll> A(K);
  REP(k, 0, K) {
    cin >> A[k];
    A[k]--;
  }
  vector<vector<ll>> nbr(N);
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll big = 1e18;
  vector dist(K, vector(N, big));
  REP(k, 0, K) {
    dist[k][A[k]] = 0;
    queue<ll> que;
    que.push(A[k]);
    while (not que.empty()) {
      auto nd = que.front(); que.pop();
      for (ll peer : nbr[nd]) {
        if (dist[k][peer] >= big) {
          dist[k][peer] = dist[k][nd] + 1;
          que.push(peer);
        }
      }
    }
  }
  REP(_q, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    ll ans = big;
    REP(k, 0, K) updMin(ans, dist[k][s] + dist[k][t]);
    cout << ans << endl;
  }
  return 0;
}

