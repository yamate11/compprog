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
  // @InpVec(N, T) [7o3ts3fF]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [7o3ts3fF]
  ll tot = 0; REP(i, 0, N) tot += T[i];

  vector<bool> tbl(tot + 1, false);
  tbl[0] = true;
  REP(i, 0, N) {
    REPrev(t, tot, 0) {
      if (not tbl[t]) continue;
      tbl[t + T[i]] = true;
    }
  }
  ll ans = tot;
  REP(t, 0, tot + 1) {
    if (tbl[t]) ans = min(ans, max(t, tot - t));
  }
  cout << ans << endl;

  return 0;
}

