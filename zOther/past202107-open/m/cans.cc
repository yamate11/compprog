#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/mincostflow>
using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  
  mcf_graph<ll, ll> graph(2*N + 3);
  const ll source = 0;
  const ll sink = 1;
  const ll end = 2;
  auto U = [&](ll i) -> ll { return 3 + i; };
  auto V = [&](ll i) -> ll { return 3 + N + i; };
  REP(i, N) {
    graph.add_edge(source, U(i), 1, 0);
    graph.add_edge(V(i), sink, 1, 0);
  }
  graph.add_edge(end, sink, N, 0);
  REP(i, N) {
    REP2(j, i + 1, N) graph.add_edge(U(i), V(j), 1, abs(A[i] - A[j]));
    graph.add_edge(U(i), end, 1, C);
  }
  auto [cap, cost] = graph.flow(source, sink);
  assert(cap == N);
  cout << cost << endl;

  return 0;
}

