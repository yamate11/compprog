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

  vector<pll> ans(101);
  ll n = 100;
  ll y = 0;
  while (n > 0) {
    ll a = 1500 / (2 * n);
    REP(i, 0, a) ans[n - i] = pll(i * 2 * n + n, y + n);
    y += 2 * n;
    n -= a;
  }
  REP(i, 1, 101) cout << ans[i].first << " " << ans[i].second << "\n";

  return 0;
}

