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

  ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  ll d = abs(ty - sy);
  ll ans = d;
  if (sy % 2 == 0) {
    if (sx % 2 != 0) sx--;
  }else {
    if (sx % 2 == 0) sx--;
  }
  if (ty % 2 == 0) {
    if (tx % 2 != 0) tx--;
  }else {
    if (tx % 2 == 0) tx--;
  }
  ll h = abs(sx - tx);
  if (h <= d) {
    // do nothing
  }else {
    h -= d;
    assert(h % 2 == 0);
    ans += h / 2;
  }
  cout << ans << endl;
  return 0;
}

