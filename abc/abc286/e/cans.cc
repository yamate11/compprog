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

  ll N; cin >> N;
  // @InpVec(N, A) [zxOU4yWd]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [zxOU4yWd]
  ll big = 1e18;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  vector dist(N, vector(N, pll(big, 0)));
  REP(i, 0, N) REP(j, 0, N) {
    if (i == j) dist[i][i] = pll(0, 0);
    else if (S[i][j] == 'Y') dist[i][j] = pll(1, A[i] + A[j]);
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) {
    if (k == i or k == j) continue;
    auto [d1, w1] = dist[i][k];
    auto [d2, w2] = dist[k][j];
    auto [dd, ww] = dist[i][j];
    if (d1 >= big or d2 >= big) continue;
    if (d1 + d2 < dd) {
      dist[i][j] = pll(d1 + d2, w1 + w2 - A[k]);
    }else if (d1 + d2 == dd and w1 + w2 - A[k] > ww) {
      dist[i][j] = pll(d1 + d2, w1 + w2 - A[k]);
    }
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll u, v; cin >> u >> v; u--; v--;
    auto [d, w] = dist[u][v];
    if (d >= big) cout << "Impossible\n";
    else cout << d << " " << w << "\n";
  }

  return 0;
}

