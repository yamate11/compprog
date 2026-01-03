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

  ll x, y; cin >> x >> y;
  ll unit = 100000;
  ll ans;
  if (x == 1 and y == 1) ans = 10;
  else {
    ll xx = 4 - x;
    ll yy = 4 - y;
    if (xx < 0) xx = 0;
    if (yy < 0) yy = 0;
    ans = xx + yy;
  }
  cout << ans * unit << endl;

  return 0;
}

