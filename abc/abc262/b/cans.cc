#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector conn(N, vector(N, false));
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    conn[u][v] = true;
    conn[v][u] = true;
  }
  ll ans = 0;
  REP(i, N) REP2(j, i, N) REP2(k, j, N) {
    if (conn[i][j] and conn[j][k] and conn[i][k]) ans++;
  }
  cout << ans << endl;

  return 0;
}

