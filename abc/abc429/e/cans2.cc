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
  vector<pll> fst(N, pll(big, -1));
  vector<pll> snd(N, pll(big, -1));
  queue<pll> que;
  REP(i, 0, N) {
    if (S[i] == 'S') {
      fst[i] = pll(0, i);
      que.emplace(i, 1);
    }
  }
  while (not que.empty()) {
    auto [nd, tp] = que.front(); que.pop();
    ll origin, dist;
    if (tp == 1) {
      tie(dist, origin) = fst[nd];
    }else {
      tie(dist, origin) = snd[nd];
    }
    for (ll peer : nbr[nd]) {
      auto [d, o] = fst[peer];
      if (o < 0) {
        fst[peer] = pll(dist + 1, origin);
        que.emplace(peer, 1);
      }else {
        auto [d2, o2] = snd[peer];
        if (o2 < 0 and o != origin) {
          snd[peer] = pll(dist + 1, origin);
          que.emplace(peer, 2);
        }
      }
    }
  }
  REP(i, 0, N) {
    if (S[i] == 'D') {
      auto [d1, o1] = fst[i];
      auto [d2, o2] = snd[i];
      cout << d1 + d2 << "\n";
    }
  }

  return 0;
}

