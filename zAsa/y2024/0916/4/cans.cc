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

  ll N, M, K; cin >> N >> M >> K;
  vector dist(N, vector(N, -1LL));
  vector conn(N, 0ULL);
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    ll w; cin >> w;
    dist[u][v] = dist[v][u] = w;
    conn[u] |= 1ULL << v;
    conn[v] |= 1ULL << u;
  }

  ll ans = 1e18;
  auto sch = [&](auto rF, ll sum, u64 x, u64 y) -> void  {
    if (x == 0) {
      if (y > 0) return;
      ans = min(ans, sum % K);
      return;
    }
    ll i = countr_zero(x);
    u64 z0 = conn[i] & y;
    u64 z = z0;
    while (true) {
      ll t = sum;
      REP(j, 0, N) if (z >> j & 1) t += dist[i][j];
      rF(rF, t, (x | z) ^ (1ULL << i), y & ~z);
      if (z == 0) break;
      z = (z - 1) & z0;
    }
  };
  sch(sch, 0, 1, ((1ULL << N) - 1) ^ 1);
  cout << ans << endl;

  return 0;
}

