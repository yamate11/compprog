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
  // @InpNbrList(N, M, fwd, dir=True, dec=1, read=(C)) [Qq3pGjcH]
  struct fwd_t {
    int nd;
    ll C;
    fwd_t() {}
    fwd_t(int nd_, ll C_) : nd(nd_), C(C_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    fwd[u].emplace_back(v, C);
  }
  // @End [Qq3pGjcH]
  ll big = 1e18;
  vector dist(N, vector(N, big));
  ll s = 0;
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, N) for (auto [nd, C] : fwd[i]) {
    dist[i][nd] = C;
    s += C;
  }
  ll ans = 0;
  REP(k, 0, N) {
    REP(i, 0, N) REP(j, 0, N) {
      ll d = dist[i][k] + dist[k][j];
      if (d < dist[i][j]) {
        if (dist[i][j] == big) {
          s += d;
        }else {
          s = s - dist[i][j] + d;
        }
        dist[i][j] = d;
      }
    }
    ans += s;
  }
  cout << ans << endl;

  return 0;
}

