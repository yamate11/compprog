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

  ll N, M; cin >> N >> M;
  vector<ll> C(N), P(N);
  vector S(N, vector<ll>());
  REP(i, 0, N) {
    cin >> C[i] >> P[i];
    S[i].resize(P[i]);
    REP(j, 0, P[i]) cin >> S[i][j];
  }
  auto big = 1e18;
  vector<double> tbl(M + 1, -10.0);
  auto f = [&](auto rF, ll x) -> double {
    double& ret = tbl[x];
    if (ret < -1.0) {
      if (x == 0) ret = 0.0;
      else {
        double emin = big;
        REP(i, 0, N) {
          ll q = 0;
          double t = 0;
          REP(j, 0, P[i]) {
            if (S[i][j] == 0) q++;
            else {
              ll y = max(0LL, x - S[i][j]);
              t += rF(rF, y);
            }
          }
          double e = (double)(C[i] * P[i] + t) / (P[i] - q);
          emin = min(emin, e);
        }
        ret = emin;
      }
    }
    return ret;
  };
  cout << f(f, M) << endl;

  return 0;
}

