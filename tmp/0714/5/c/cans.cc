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
  if (M == 0) {
    REP2(i, 1, N + 1) cout << 2 * i << " " << 2 * i + 1 << "\n";
    return 0;
  }
  if (M < 0 or M >= N - 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << 3 * (N - 2 - M) + 2 << " " << 3 * (N - 1) + 2 << "\n";
  REP2(i, 1, N) {
    cout << 3 * i << " " << 3 * i + 1 << "\n";
  }

  return 0;
}

