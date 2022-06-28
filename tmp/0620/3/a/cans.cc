#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x, y; cin >> x >> y;
  ll ans = 1e10;
  if (x <= y) ans = min(ans, y - x);
  if (-x <= y) ans = min(ans, y + x + 1);
  if (x <= -y) ans = min(ans, -y - x + 1);
  if (-x <= -y) ans = min(ans, -y + x + 2); 
  cout << ans << endl;

  return 0;
}

