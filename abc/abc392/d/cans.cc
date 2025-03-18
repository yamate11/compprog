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

  ll lim = 1e5 + 1;
  ll N; cin >> N;
  vector<ll> K(N);
  vector P(N, vector<ll>(lim));
  REP(i, 0, N) {
    ll k; cin >> k;
    K[i] = k;
    REP(j, 0, k) {
      ll a; cin >> a;
      P[i][a]++;
    }
  }
  double ans = 0;
  REP(i, 0, N) {
    vector<double> X(N, 0.0);
    REP(x, 1, lim) {
      if (P[i][x] > 0) {
        REP(j, i + 1, N) {
          if (P[j][x] > 0) {
            X[j] += (double)P[i][x] * P[j][x] / K[i] / K[j];
          }
        }
      }
    }
    REP(j, i + 1, N) ans = max(ans, X[j]);
  }
  cout << ans << endl;
  

  return 0;

}

