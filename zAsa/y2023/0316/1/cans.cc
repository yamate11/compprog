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
  // @InpVec(H, C, type=string) [Uc29S810]
  auto C = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; C[i] = v; }
  // @End [Uc29S810]
  vector<ll> ans;
  REP(i, 0, W) {
    ll s = 0;
    REP(j, 0, H) if (C[j][i] == '#') s ++;
    ans.push_back(s);
  }
  REPOUT(i, 0, W, ans[i], " ");

  return 0;
}

