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

  ll W, H, N; cin >> W >> H >> N;
  vector A(W, vector(H, 0));
  REP(i, 0, N) {
    ll x0, y0, a; cin >> x0 >> y0 >> a;
    if (a == 1) {
      REP(x, 0, x0) REP(y, 0, H) A[x][y] = 1;
    }else if (a == 2) {
      REP(x, x0, W) REP(y, 0, H) A[x][y] = 1;
    }else if (a == 3) {
      REP(x, 0, W) REP(y, 0, y0) A[x][y] = 1;
    }else if (a == 4) {
      REP(x, 0, W) REP(y, y0, H) A[x][y] = 1;
    }
  }
  ll ans = 0;
  REP(x, 0, W) REP(y, 0, H) if (A[x][y] == 0) ans++;
  cout << ans << endl;

  return 0;
}

