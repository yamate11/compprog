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
  ll ans = 0;
  REP(j, 9) REP(i, N) if (S[i][j] == 'x') ans++;
  REP(j, 9) {
    REP(i, N) {
      if (S[i][j] != 'o') continue;
      if (i == 0 or S[i - 1][j] != 'o') ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

