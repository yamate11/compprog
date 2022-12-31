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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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
  // @InpNbrList(N, M, nbr, dec=1, read=((C,char))) [SBPm1R6y]
  struct nbr_t {
    int nd;
    char C;
    nbr_t() {}
    nbr_t(int nd_, char C_) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    char C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [SBPm1R6y]
  auto enc = [&](ll x, ll y) -> ll { return N * x + y; };
  vector<bool> dc(N * N);
  REP(i, 0, N) for (auto& p : nbr[i]) dc[enc(i, p.nd)] = true;
  ll big = 1e18;
  vector<ll> dist(N * N, big);
  dist[enc(0, N-1)] = 0;
  queue<pll> que;
  que.emplace(0, N - 1);
  ll ans = big;
  while (not que.empty()) {
    auto [x, y] = que.front(); que.pop();
    ll d = dist[enc(x, y)];
    if (d * 2 >= ans) break;
    if (x == y) {
      ans = min(ans, 2 * d);
      continue;
    }
    if (dc[enc(x, y)]) {
      ans = min(ans, 2 * d + 1);
      continue;
    }
    for (auto& p : nbr[x]) for (auto& q : nbr[y]) if (p.C == q.C and d + 1 < dist[enc(p.nd, q.nd)]) {
          dist[enc(p.nd, q.nd)] = d + 1;
          que.emplace(p.nd, q.nd);
        }
  }
  cout << (ans == big ? -1 : ans) << endl;

  return 0;
}

