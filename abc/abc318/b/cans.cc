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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto rec = vector(100, vector(100, false));
  REP(i, 0, N) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    REP(x, a, b) REP(y, c, d) rec[x][y] = true;
  }
  ll ans = 0;
  REP(i, 0, 100) REP(j, 0, 100) if (rec[i][j]) ans++;
  cout << ans << endl;
  return 0;
}

