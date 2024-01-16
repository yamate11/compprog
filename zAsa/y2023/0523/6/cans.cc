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
  ll g = 0;
  REP(i, 0, N) {
    ll X, Y, Z; cin >> X >> Y >> Z;
    ll M; cin >> M;
    ll ax, bx, ay, by, az, bz;
    ax = ay = az = LLONG_MAX;
    bx = by = bz = LLONG_MIN;
    REP(j, 0, M) {
      ll x, y, z; cin >> x >> y >> z;
      ax = min(ax, x); bx = max(bx, x);
      ay = min(ay, y); by = max(by, y);
      az = min(az, z); bz = max(bz, z);
    }
    g ^= ax ^ ay ^ az ^ (X - bx - 1) ^ (Y - by - 1) ^ (Z - bz - 1);
  }
  if (g == 0) cout << "LOSE\n";
  else cout << "WIN\n";

  return 0;
}

