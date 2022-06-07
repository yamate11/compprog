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
  vector A(N, vector<ll>());
  REP(i, N) {
    A[i].resize(i + 1);
    REP(j, i + 1) {
      if (j == 0 or j == i) A[i][j] = 1;
      else A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
    }
  }
  REP(i, N) {
    REP(j, i + 1) cout << A[i][j] << " ";
    cout << "\n";
  }

  return 0;
}

