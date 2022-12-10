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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  pll ans(-1, -1);
  REP(d, 1, 10) {
    ll m = 0;
    REP(i, 1, N + 1) {
      m = (10 * m + d) % M;
      if (m == 0) {
        auto [k, e] = ans;
        if (i > k or (i == k and d > e)) ans = pll(i, d);
      }
    }
  }
  auto [k, e] = ans;
  if (k < 0) cout << -1 << endl;
  else {
    REPOUT(i, 0, k, e, "");
  }

  return 0;
}

