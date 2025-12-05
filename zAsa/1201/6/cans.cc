#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/mincostflow>
using namespace atcoder;
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
  // @InpVec(N, S, type=string) [Dhj2PwJV]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [Dhj2PwJV]

  ll source = N * M;
  ll sink = N * M + 1;
  auto enc = [&](ll i, ll j) -> ll { return i * M + j; };

  ll big = 200;
  mcf_graph<ll, ll> g(N*M + 2);
  ll numpiece = 0;
  REP(i, 0, N) REP(j, 0, M) {
    if (S[i][j] == 'o') {
      g.add_edge(source, enc(i, j), 1, i + j);
      numpiece++;
    }
    if (S[i][j] != '#') {
      g.add_edge(enc(i, j), sink, 1, (N - 1 - i) + (M - 1 - j));
    }
    if (i + 1 < N and S[i][j] != '#' and S[i + 1][j] != '#') g.add_edge(enc(i, j), enc(i + 1, j), big, 0);
    if (j + 1 < M and S[i][j] != '#' and S[i][j + 1] != '#') g.add_edge(enc(i, j), enc(i, j + 1), big, 0);
  }
  auto [flow, cost] = g.flow(source, sink);
  cout << ((N - 1) + (M - 1)) * numpiece - cost << endl;

  return 0;
}

