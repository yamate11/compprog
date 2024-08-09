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

  ll x, y, r, n; cin >> x >> y >> r >> n;
  vector<string> ans(2*n + 1, string(2*n + 1, ' '));
  REP(i, 0, 2 * n + 1) REP(j, 0, 2 * n + 1) {
    ll dx = (x + n) - i;
    ll dy = (y + n) - j;
    ll dd = dx * dx + dy * dy;
    if (dd > r * r) ans[i][j] = '.';
    else ans[i][j] = '#';
  }
  REP(i, 0, 2 * n + 1) {
    REP(j, 0, 2 * n + 1) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

