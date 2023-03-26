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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dir=True, dec=1) [9q5rPKLN]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [9q5rPKLN]
  
  vector tbl(N, -1.0);
  auto f = [&](auto rF, ll n) -> double {
    double& ret = tbl[n];
    if (ret < 0) {
      if (n == N-1) ret = 0.0;
      else {
        double s = 0.0;
        for (ll m : fwd[n]) s += rF(rF, m);
        ret = 1.0 + s / SIZE(fwd[n]);
      }
    }
    return ret;
  };
  double ans = f(f, 0);
  REP(k, 0, N) {
    if (SIZE(fwd[k]) == 1) continue;
    vector tmp(N, -1.0);
    auto g = [&](auto rF, ll n) -> double {
      double& ret = tmp[n];
      if (ret < 0) {
        if (n == N - 1) ret = 0.0;
        else if (k < n) ret = f(f, n);
        else if (n == k) {
          double vmax = 0.0;
          double s = 0.0;
          for (ll m : fwd[k]) {
            double v = f(f, m);
            s += v;
            vmax = max(vmax, v);
          }
          ret = 1.0 + (s - vmax) / (SIZE(fwd[k]) - 1);
        }else {
          double s = 0.0;
          for (ll m : fwd[n]) s += rF(rF, m);
          ret = 1.0 + s / SIZE(fwd[n]);
        }
      }
      return ret;
    };
    ans = min(ans, g(g, 0));
  }
  cout << ans << endl;
  return 0;
}

