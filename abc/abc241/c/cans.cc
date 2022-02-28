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
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    REP(i, N) REP(j, N) {
      if (j + 6 <= N) {
        ll c = 0;
        REP(k, 6) if (S[i][j + k] == '#') c += 1;
        if (c >= 4) return true;
      }
      if (i + 6 <= N) {
        ll c = 0;
        REP(k, 6) if (S[i + k][j] == '#') c += 1;
        if (c >= 4) return true;
      }
      if (j + 6 <= N and i + 6 <= N) {
        ll c = 0;
        REP(k, 6) if (S[i + k][j + k] == '#') c += 1;
        if (c >= 4) return true;
      }
      if (i >= 5 and j + 6 <= N) {
        ll c = 0;
        REP(k, 6) if (S[i - k][j + k] == '#') c += 1;
        if (c >= 4) return true;
      }

    }
    return false;
  };

  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

