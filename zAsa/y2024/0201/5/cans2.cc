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

  ll N, W; cin >> N >> W;
  vector val(4, vector<ll>());
  ll w_base = -1;
  REP(i, 0, N) {
    ll w, v; cin >> w >> v;
    if (i == 0) {
      w_base = w;
      val[0].push_back(v);
    }
    else val[w - w_base].push_back(v);
  }
  REP(i, 0, 4) sort(ALL(val[i]), greater<ll>());
  vector acc(4, vector<ll>());
  REP(i, 0, 4) {
    ll sz = SIZE(val[i]);
    acc[i].resize(sz + 1, 0LL);
    REP(j, 0, sz) acc[i][j + 1] = acc[i][j] + val[i][j];
  }
  ll ans = 0;
  REP(i, 0, SIZE(val[0]) + 1) {
    ll w0 = w_base * i;
    ll v0 = acc[0][i];
    if (w0 > W) break;
    REP(j, 0, SIZE(val[1]) + 1) {
      ll w1 = (w_base + 1) * j;
      ll v1 = acc[1][j];
      if (w0 + w1 > W) break;
      REP(k, 0, SIZE(val[2]) + 1) {
        ll w2 = (w_base + 2) * k;
        ll v2 = acc[2][k];
        if (w0 + w1 + w2 > W) break;
        ll m = (W - (w0 + w1 + w2)) / (w_base + 3);
        m = min(m, SIZE(val[3]));
        ll v3 = acc[3][m];
        ans = max(ans, v0 + v1 + v2 + v3);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

