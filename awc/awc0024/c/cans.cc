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

  ll n_alph = 26;

  ll H, W; cin >> H >> W;
  // @InpVec(H, G, type=string) [Lb4G4pG7]
  auto G = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; G[i] = v; }
  // @End [Lb4G4pG7]

  vector ok(H, vector(W, true));

  REP(i, 0, H) {
    vector vec(n_alph, 0LL);
    REP(j, 0, W) vec[G[i][j] - 'a']++;
    REP(j, 0, W) if (vec[G[i][j] - 'a'] != 1) ok[i][j] = false;
  }
  REP(i, 0, W) {
    vector vec(n_alph, 0LL);
    REP(j, 0, H) vec[G[j][i] - 'a']++;
    REP(j, 0, H) if (vec[G[j][i] - 'a'] != 1) ok[j][i] = false;
  }
  string ans;
  REP(i, 0, H) REP(j, 0, W) {
    if (ok[i][j]) ans += G[i][j];
  }
  cout << ans << endl;

  return 0;
}

