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

  ll H, W; cin >> H >> W;
  // @InpVec(H, S, type=string) [FZ5GmpUj]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [FZ5GmpUj]
  ll ans = 0;
  REP(i, 1, H) REP(j, 1, W) {
    ll cnt = 0;
    if (S[i - 1][j - 1] == '#') cnt++;
    if (S[i - 1][j - 0] == '#') cnt++;
    if (S[i - 0][j - 1] == '#') cnt++;
    if (S[i - 0][j - 0] == '#') cnt++;
    if (cnt % 2 != 0) ans++;
  }
  cout << ans << endl;

  return 0;
}

