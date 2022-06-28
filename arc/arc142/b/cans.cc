#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector ans(N, vector(N, 0LL));
  REP(i, N) {
    ans[i][0] = i * N;
    ans[i][1] = (i + 1) * N - 1;
    REP2(j, 2, N) {
      if (j % 2 == 0) ans[i][j] = ans[i][j - 2] + 1;
      else            ans[i][j] = ans[i][j - 2] - 1;
    }
  }
  REP(i, N) {
    REP(j, N) cout << ans[i][j] + 1 << " ";
    cout << "\n";
  }

  return 0;
}

