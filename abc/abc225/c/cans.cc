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

  ll N, M; cin >> N >> M;
  vector B(N, vector<ll>(M, 0LL));
  REP(i, N) REP(j, M) cin >> B[i][j];
  ll base = B[0][0];
  REP(i, N) {
    if (B[i][0] - base != 7 * i) {
      cout << "No\n";
      return 0;
    }
    REP(j, M) {
      if (B[i][j] - B[i][0] != j) {
        cout << "No\n";
        return 0;
      }
      if (B[i][j] % 7 == 0 and j != M-1) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";

  return 0;
}

