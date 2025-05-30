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

  ll H, W, K; cin >> H >> W >> K;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  ll ans = 0;
  REP(x, 0, 1LL << H) REP(y, 0, 1LL << W) {
    ll cnt = 0;
    REP(i, 0, H) if (x >> i & 1) REP(j, 0, W) if (y >> j & 1) if (S[i][j] == '#') cnt++;
    if (cnt == K) ans++;
  }
  cout << ans << endl;

  return 0;
}

