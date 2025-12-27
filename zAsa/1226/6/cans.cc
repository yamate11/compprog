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
  // @InpNbrList(N, M, nbr, dec=1, read=((C, char))) [cxlYFmKT]
  struct nbr_t {
    int nd;
    char C;
    nbr_t(int nd_ = int(), char C_ = char()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    char C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [cxlYFmKT]

  vector conn(N, vector(N, false));
  REP(i, 0, N) for (auto [j, c] : nbr[i]) conn[i][j] = true;

  ll big = 1e18;
  ll cand = big;
  vector dist(N, vector(N, big));
  queue<pll> que;
  dist[0][N - 1] = 0;
  que.emplace(0, N - 1);
  while (not que.empty()) {
    auto [i, j] = que.front(); que.pop();
    if (i == j) {
      cand = min(cand, 2 * dist[i][j]);
      break;
    }
    if (conn[i][j]) cand = min(cand, 2 * dist[i][j] + 1);
    for (auto [pi, ci]: nbr[i]) {
      for (auto [pj, cj]: nbr[j]) {
        if (ci == cj) {
          ll a = pi, b = pj;
          if (a > b) swap(a, b);
          if (dist[a][b] == big) {
            dist[a][b] = dist[i][j] + 1;
            que.emplace(a, b);
          }
        }
      }
    }
  }
  if (cand == big) cand = -1;
  cout << cand << endl;


  return 0;
}

