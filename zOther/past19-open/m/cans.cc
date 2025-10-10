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
  // @InpVec(N, P) [Ioe5E3zP]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [Ioe5E3zP]
  using sta = pair<ll, double>;
  vector fwd(N, vector<sta>());
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    double w; cin >> w;
    fwd[u].emplace_back(v, w);
  }
  vector score(N, -10.0);
  auto calc = [&](auto rF, ll nd) -> double {
    double& r = score[nd];
    if (r < -9.5) {
      if (nd == N - 1) r = P[nd];
      else {
        double val = -1.0;
        for (auto [peer, w] : fwd[nd]) {
          double pv = rF(rF, peer);
          if (pv >= 0) {
            val = max(val, w * rF(rF, peer));
          }
        }
        if (val < 0) r = -1.0;
        else r = P[nd] + val;
      }
    }
    return r;
  };
  double ans = calc(calc, 0);
  if (ans < 0.0) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }
  

  return 0;
}

