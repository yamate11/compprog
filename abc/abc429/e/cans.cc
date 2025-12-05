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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [wjK0mciI]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [wjK0mciI]
  string S; cin >> S;

  ll big = 1e18;

  auto f = [&](const auto& V) -> vector<ll> {
    vector<ll> dist(N, big);
    queue<ll> que;
    for (ll nd : V) {
      dist[nd] = 0;
      que.push(nd);
    }
    while (not que.empty()) {
      auto nd = que.front(); que.pop();
      for (ll peer : nbr[nd]) {
        if (dist[peer] == big) {
          dist[peer] = dist[nd] + 1;
          que.push(peer);
        }
      }
    }
    return dist;
  };

  vector<ll> ans(N, big);
  REP(k, 0, countr_zero(bit_ceil((u64(N + 1))))) {
    vector<ll> A, B;
    REP(i, 0, N) if (S[i] == 'S') {
      if (i >> k & 1) B.push_back(i);
      else A.push_back(i);
    }
    if (A.empty() or B.empty()) continue;
    auto distA = f(A);
    auto distB = f(B);
    REP(i, 0, N) updMin(ans[i], distA[i] + distB[i]);
  }
  REP(i, 0, N) if (S[i] == 'D') cout << ans[i] << "\n";
  return 0;
}

