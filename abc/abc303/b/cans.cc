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
  // @InpGrid(M, N, A, dec=1) [USAqFSzI]
  auto A = vector(M, vector(N, ll()));
  for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; v -= 1; A[i][j] = v; }
  // @End [USAqFSzI]

  vector adj(N, vector(N, false));
  REP(i, 0, M) REP(j, 0, N - 1) {
    ll a = A[i][j];
    ll b = A[i][j + 1];
    adj[a][b] = true;
    adj[b][a] = true;
  }
  ll cnt = 0;
  REP(i, 0, N) REP(j, i + 1, N) {
    if (not adj[i][j]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

