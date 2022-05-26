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
  vector<string> S(N);
  REP(i, N) cin >> S[i];
  vector A(10, vector(10, 0LL));
  REP(i, N) REP(j, 10) A[S[i][j] - '0'][j]++;
  ll ans = 1e9;
  REP(d, 10) {
    ll thisK = 0;
    REP(i, 10) {
      if (A[d][i] > 0) {
        thisK = max(thisK, (A[d][i] - 1) * 10 + i);
      }
    }
    ans = min(ans, thisK);
  }
  cout << ans << endl;

  return 0;
}

