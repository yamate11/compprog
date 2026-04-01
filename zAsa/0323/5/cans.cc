#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  ll N; cin >> N;
  // @InpMVec(N, ((A, dec=1), (B, dec=1))) [8AaRFdvU]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [8AaRFdvU]

  ll numNodes = 1 + max(*ranges::max_element(A), *ranges::max_element(B));

  ll source = 0;
  ll dest = 1;
  auto edge = [&](ll i) -> ll { return i + 2; };
  auto node = [&](ll i) -> ll { return 2 + N + i; };

  mf_graph<ll> graph(2 + N + numNodes);
  REP(i, 0, N) {
    graph.add_edge(source, edge(i), 1);
    graph.add_edge(edge(i), node(A[i]), 1);
    graph.add_edge(edge(i), node(B[i]), 1);
  }
  REP(i, 0, numNodes) graph.add_edge(node(i), dest, 1);
  cout << graph.flow(source, dest) << endl;

  

  return 0;
}

