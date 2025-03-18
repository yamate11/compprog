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

  ll R, C, D; cin >> R >> C >> D;
  // @InpGrid(R, C, A) [v0XtUFMy]
  auto A = vector(R, vector(C, ll()));
  for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [v0XtUFMy]

  ll ans = 0;
  REP(i, 0, R) REP(j, 0, C) {
    if (i + j <= D and (i + j - D) % 2 == 0) {
      ans = max(ans, A[i][j]);
    }
  }
  cout << ans << endl;

  return 0;
}

