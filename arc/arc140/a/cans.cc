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

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  REP2(m, 1, N + 1) {
    if (N % m != 0) continue;
    vector cnt(m, vector(26, 0LL));
    REP(i, N) cnt[i % m][S[i] - 'a']++;
    ll chg = 0;
    REP(i, m) {
      ll cmax = 0;
      REP(j, 26) cmax = max(cmax, cnt[i][j]);
      chg += (N / m) - cmax;
    }
    if (chg <= K) {
      cout << m << endl;
      return 0;
    }
  }
  assert(0);

  return 0;
}

