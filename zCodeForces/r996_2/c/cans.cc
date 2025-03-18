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
    ll N, M; cin >> N >> M;
    string S; cin >> S;
    // @InpGrid(N, M, A) [TAGpOnNu]
    auto A = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
    // @End [TAGpOnNu]
    ll r = 0, c = 0;
    REP(idx, 0, N + M - 2) {
      ll ch = S[idx];
      if (ch == 'D') {
        ll s = 0;
        REP(i, 0, M) s += A[r][i];
        A[r][c] = -s;
        r++;
      }else {
        ll s = 0;
        REP(i, 0, N) s += A[i][c];
        A[r][c] = -s;
        c++;
      }
    }
    ll s = 0;
    REP(i, 0, M) s += A[N - 1][i];
    A[N - 1][M - 1] = -s;
    REP(i, 0, N) {
      REPOUT(j, 0, M, A[i][j], " ");
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

