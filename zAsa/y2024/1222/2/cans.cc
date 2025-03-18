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

  ll a, b, c; cin >> a >> b >> c;
  ll ans = 0;
  set<pll> seen;
  REP(i, 0, 1000) {
    if (seen.contains(pll(a, b))) {
      cout << -1 << endl;
      return 0;
    }
    seen.insert(pll(a, b));
    if (a % 2 != 0 or b % 2 != 0 or c % 2 != 0) {
      cout << ans << endl;
      return 0;
    }
    ll na = 0, nb = 0, nc = 0;
    nb += a / 2;
    nc += a / 2;
    nc += b / 2;
    na += b / 2;
    na += c / 2;
    nb += c / 2;
    a = na;
    b = nb;
    c = nc;
    ans++;
  }

  return 0;
}

