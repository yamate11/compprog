#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
#include <atcoder/maxflow>
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

  ll H, W, N; cin >> H >> W >> N;
  // @InpMVec(N, ((A, dec=1), (B, dec=1), (C, dec=1), (D, dec=1))) [Cxqg16lJ]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; v3 -= 1; C[i] = v3;
    ll v4; cin >> v4; v4 -= 1; D[i] = v4;
  }
  // @End [Cxqg16lJ]

  ll source = 0;
  ll sink = 1;
  auto encRow = [&](ll i) { return 2 + i; };
  auto encCol = [&](ll i) { return 2 + H + i; };
  auto encPR  = [&](ll i) { return 2 + H + W + i; };
  auto encPC  = [&](ll i) { return 2 + H + W + N + i; };
  ll numNodes = 2 + H + W + N + N;

  mf_graph<ll> graph(numNodes);
  REP(i, 0, H) graph.add_edge(source, encRow(i), 1);
  REP(i, 0, W) graph.add_edge(encCol(i), sink, 1);
  REP(i, 0, N) {
    graph.add_edge(encPR(i), encPC(i), 1);
    REP(j, A[i], C[i] + 1) graph.add_edge(encRow(j), encPR(i), 1);
    REP(j, B[i], D[i] + 1) graph.add_edge(encPC(i), encCol(j), 1);
  }
  ll f = graph.flow(source, sink);
  cout << f << endl;

  return 0;
}

