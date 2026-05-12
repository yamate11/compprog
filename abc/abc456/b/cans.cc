#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // @InpGrid(3, 6, A) [nAJoUTGc]
  auto A = vector(3, vector(6, ll()));
  for (int i = 0; i < 3; i++) for (int j = 0; j < 6; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [nAJoUTGc]

  vector B(3, vector<ll>(7));
  REP(i, 0, 3) {
    REP(j, 0, 6) B[i][A[i][j]]++;
  }
  vector<vector<ll>> perm{{4, 5, 6}, {4, 6, 5}, {5, 4, 6}, {5, 6, 4}, {6, 4, 5}, {6, 5, 4}};
  double ans = 0;
  for (auto vec : perm) {
    double cur = 1;
    REP(i, 0, 3) {
      cur *= B[i][vec[i]] / 6.0;
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}

