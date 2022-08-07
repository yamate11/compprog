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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    vector<string> A(N);
    REP(i, N) cin >> A[i];
    REP(i, N) REP(j, N) {
      if (i == j) continue;
      if (A[i][j] == 'D') {
        if (A[j][i] != 'D') return false;
      }
      if (A[i][j] == 'W') {
        if (A[j][i] != 'L') return false;
      }
      if (A[i][j] == 'L') {
        if (A[j][i] != 'W') return false;
      }
    }
    return true;
  };
  cout << (solve() ? "correct" : "incorrect") << endl;

  return 0;
}

