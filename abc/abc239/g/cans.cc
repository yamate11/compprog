#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/maxflow>
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

  ll N, M; cin >> N >> M;
  mf_graph<ll> graph(2*N);
  const ll big = 1e15;
  REP(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    graph.add_edge(2*a + 1, 2 * b, big);
    graph.add_edge(2*b + 1, 2 * a, big);
  }
  REP(i, N) {
    ll c; cin >> c;
    graph.add_edge(2*i, 2*i + 1, c);
  }
  ll ans = graph.flow(1, 2*(N - 1));
  cout << ans << endl;
  auto mc = graph.min_cut(1);
  vector<ll> ps;
  REP2(i, 1, N-1) {
    if (mc[2*i] and not mc[2*i + 1]) ps.push_back(i);
  }
  cout << SIZE(ps) << endl;
  for(ll p : ps) cout << p + 1 << " ";
  cout << endl;


  return 0;
}

