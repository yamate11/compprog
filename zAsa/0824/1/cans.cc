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

  ll H, W; cin >> H >> W;
  // @InpVec(H, S, type=string) [haAQFpRr]
  auto S = vector(H, string());
  for (int i = 0; i < H; i++) { string v; cin >> v; S[i] = v; }
  // @End [haAQFpRr]
  ll ans = 0;
  REP(i, 0, H) {
    REP(j, 0, W - 1) if (S[i][j] == '.' and S[i][j + 1] == '.') ans++;
  }
  REP(j, 0, W) {
    REP(i, 0, H - 1) if (S[i][j] == '.' and S[i + 1][j] == '.') ans++;
  }
  cout << ans << endl;

  return 0;
}

