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
  vector<string> S(N); REP(i, N) cin >> S[i];
  sort(ALL(S), [&](const string& s, const string& t) -> bool { return s + t < t + s; });
  string bigs(1, char('z' + 1));
  vector tbl(N + 1, vector<string>(K + 1, bigs));
  REP(i, N + 1) tbl[i][0] = "";
  REP2R(i, N-1, 0) REP2(j, 1, min(K, N - i) + 1) {
    tbl[i][j] = min(tbl[i+1][j], S[i] + tbl[i+1][j-1]);
  }
  cout << tbl[0][K] << endl;

  return 0;
}

