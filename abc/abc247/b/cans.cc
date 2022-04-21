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
  vector rn(N, vector<string>(2));
  REP(i, N) {
    cin >> rn[i][0] >> rn[i][1];
  }
  vector rec(N, vector(2, true));
  REP(i, N) REP(p, 2) {
    REP2(j, i + 1, N) REP(q, 2) {
      if (rn[i][p] == rn[j][q]) {
        rec[i][p] = false;
        rec[j][q] = false;
      }
    }
  }
  REP(i, N) {
    if ((not rec[i][0]) and (not rec[i][1])) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

