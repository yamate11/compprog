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

int main() {
  ll N, C; cin >> N >> C;
  ll lim = 1e5;
  vector vec(lim + 1, vector(C, 0LL));
  REP(i, 0, N) {
    ll s, t, c; cin >> s >> t >> c; c--;
    REP(j, s, t + 1) vec[j][c] = 1;
  }
  ll ans = 0;
  REP(j, 0, lim + 1) ans = max(ans, accumulate(ALL(vec[j]), 0LL));
  cout << ans << endl;

  return 0;
}

