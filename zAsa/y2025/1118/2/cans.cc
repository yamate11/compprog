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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector conn(N, vector(N, false));
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    conn[u][v] = conn[v][u] = true;
  }

  ll cnt = 0;
  REP(a, 0, N) REP(b, a + 1, N) REP(c, b + 1, N) {
    if (conn[a][b] and conn[b][c] and conn[c][a]) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

