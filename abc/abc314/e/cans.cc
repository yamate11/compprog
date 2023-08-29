#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll N, M; cin >> N >> M;
  vector<ll> C(N);
  vector<ll> P(N);
  vector<vector<ll>> S(N);
  REP(i, 0, N) {
    cin >> C[i] >> P[i];
    S[i].resize(P[i]);
    REP(j, 0, P[i]) cin >> S[i][j];
  }

  vector tbl(M + 1, -1.0);
  auto e = [&](auto rF, ll m) -> double {
    if (m <= 0) return 0.0;
    double& ret = tbl[m];
    if (ret < 0) {
      ret = 1e18;
      REP(i, 0, N) {
        ll zero = 0;
        double z = P[i] * C[i];
        REP(j, 0, P[i]) {
          if (S[i][j] == 0) zero++;
          else z += rF(rF, m - S[i][j]);
        }
        double t = z / (P[i] - zero);
        ret = min(ret, t);
      }
    }
    return ret;
  };

  cout << e(e, M) << endl;

  return 0;
}

