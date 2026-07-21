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
    // @InpGrid(N, N, X) [rUiLEexV]
    auto X = vector(N, vector(N, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; X[i][j] = v; }
    // @End [rUiLEexV]
    REP(i, 0, N) REP(j, 0, N) {
      if      (X[i][j] == 1) X[i][j] = 2;
      else if (X[i][j] == 2) X[i][j] = 4;
      else if (X[i][j] == 3) X[i][j] = 1;
      else if (X[i][j] == 4) X[i][j] = 3;
      else assert(0);
    }
    REP(i, 0, N) {
      REPOUT(j, 0, N, X[i][j], " ");
    }

  };

  solve();

  return 0;
}

