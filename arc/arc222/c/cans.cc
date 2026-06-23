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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpGrid(N, N, A) [0WhvkwNh]
    auto A = vector(N, vector(N, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
    // @End [0WhvkwNh]
    ll big = 1LL << 60;
    vector t0(N, vector(N, 0LL));
    vector tD(N, vector(N, 0LL));
    vector tU(N, vector(N, 0LL));
    REP(i, 0, N) REP(j, 0, N) {
      ll a = j == 0 ? 0 : A[i][j - 1];
      ll b = j == N - 1 ? 0 : A[i][j + 1];
      t0[i][j] = a + b;
    }
    REPrev(i, N - 1, 0) REP(j, 0, N) {
      tD[i][j] = t0[i][j];
      if (i < N - 1) {
        ll aa = j == 0 ? big : tD[i + 1][j - 1];
        ll bb = j == N - 1 ? big : tD[i + 1][j + 1];
        tD[i][j] += min(aa, bb);
      }
    }
    REP(i, 0, N) REP(j, 0, N) {
      tU[i][j] = t0[i][j];
      if (i > 0) {
        ll aa = j == 0     ? big : tU[i - 1][j - 1];
        ll bb = j == N - 1 ? big : tU[i - 1][j + 1];
        tU[i][j] += min(aa, bb);
      }
    }
    vector ans(N, vector(N, 0LL));
    REP(i, 0, N) REP(j, 0, N) {
      ll a, b;
      if (j == 0)     a = big;
      else            a = tD[i][j - 1] + tU[i][j - 1] - t0[i][j - 1];
      if (j == N - 1) b = big;
      else            b = tD[i][j + 1] + tU[i][j + 1] - t0[i][j + 1];
      ans[i][j] = min(a, b);
    }
    REP(i, 0, N) {
      REPOUT(j, 0, N, ans[i][j], " ");
    }
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

