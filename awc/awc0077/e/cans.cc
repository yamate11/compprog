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

  ll N, M; cin >> N >> M;
  // @InpVec(M, B) [tNur8zi8]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [tNur8zi8]
  mf_graph<ll> graph(N + M + 2);
  REP(i, 0, N) {
    graph.add_edge(N + M, i, 1);
    ll k; cin >> k;
    REP(j, 0, k) {
      ll c; cin >> c; c--;
      graph.add_edge(i, N + c, 1);
    }
  }
  REP(i, 0, M) graph.add_edge(N + i, N + M + 1, B[i]);
  ll ans = graph.flow(N + M, N + M + 1);
  cout << ans << endl;

  return 0;
}

