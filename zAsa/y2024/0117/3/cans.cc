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
  // @InpGrid(N, 9, X, type=char) [MvuuGfP3]
  auto X = vector(N, vector(9, char()));
  for (int i = 0; i < N; i++) for (int j = 0; j < 9; j++) { char v; cin >> v; X[i][j] = v; }
  // @End [MvuuGfP3]

  ll ans = 0;
  REP(j, 0, 9) {
    REP(i, 0, N) {
      if (X[i][j] == 'x') ans++;
      else if (X[i][j] == 'o' and (i == 0 or X[i - 1][j] != 'o')) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

