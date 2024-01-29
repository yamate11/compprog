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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [aKjYr4BB]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [aKjYr4BB]

    vector B(N - 1, 0LL);
    vector C(N - 1, 0LL);
    B[0] = 1;
    C[N - 2] = 1;
    REP(i, 1, N - 1) {
      if (A[i] - A[i - 1] < A[i + 1] - A[i]) {
        B[i] = A[i + 1] - A[i];
        C[i - 1] = 1;
      }else {
        B[i] = 1;
        C[i - 1] = A[i] - A[i - 1];
      }
    }
    vector SB(N, 0LL);
    vector SC(N, 0LL);
    REP(i, 0, N - 1) SB[i + 1] = SB[i] + B[i];
    REPrev(i, N - 2, 0) SC[i] = SC[i + 1] + C[i];
    ll M; cin >> M;
    REP(_m, 0, M) {
      ll x, y; cin >> x >> y; x--; y--;
      if (x < y) {
        cout << SB[y] - SB[x] << "\n";
      }else if (x > y) {
        cout << SC[y] - SC[x] << "\n";
      }else assert(0);
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

