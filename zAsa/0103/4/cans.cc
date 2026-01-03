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
  if (sy > ty) {
    swap(sx, tx);
    swap(sy, ty);
  }
  assert(sy <= ty);
  if (sy % 2 == 0 and sx % 2 != 0) sx--;
  if (sy % 2 != 0 and sx % 2 == 0) sx--;
  if (ty % 2 == 0 and tx % 2 != 0) tx--;
  if (ty % 2 != 0 and tx % 2 == 0) tx--;
  ll h = ty - sy;
  ll ans;
  if      (tx < sx - h) ans = h + (sx - h - tx) / 2;
  else if (sx + h < tx) ans = h + (tx - (sx + h)) / 2;
  else                  ans = h;
  cout << ans << endl;
  


  return 0;
}

