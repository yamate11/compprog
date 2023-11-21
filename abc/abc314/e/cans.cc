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
  vector C(N, 0LL);
  vector P(N, 0LL);
  vector S(N, vector<ll>());
  REP(i, 0, N) {
    cin >> C[i] >> P[i];
    S[i].resize(P[i]);
    REP(j, 0, P[i]) cin >> S[i][j];
  }
  double big = 1e9;
  vector tbl(M + 1, big);
  auto f = [&](auto rF, ll m) -> double {
    if (m <= 0) return 0.0;
    double& ret = tbl[m];
    if (ret > 0.99 * big) {
      REP(_rep, 0, 100) {
        REP(i, 0, N) {
          double e = 0.0;
          REP(j, 0, P[i]) {
            if (S[i][j] == 0) e += ret;
            else e += rF(rF, m - S[i][j]);
          }
          e /= P[i];
          ret = min(ret, C[i] + e);
        }
      }
    }
    return ret;
  };
  cout << f(f, M) << endl;


  return 0;
}

