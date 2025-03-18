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

  ll N, M, C; cin >> N >> M >> C;
  // @InpVec(M, B) [7xtobGE8]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [7xtobGE8]
  // @InpGrid(N, M, A) [Pc8yfaOt]
  auto A = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [Pc8yfaOt]

  ll ans = 0;
  REP(i, 0, N) {
    ll s = C;
    REP(j, 0, M) s += A[i][j] * B[j];
    if (s > 0) ans++;
  }
  cout << ans << endl;

  return 0;
}

