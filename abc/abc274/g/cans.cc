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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  auto enc = [&](int dir, ll r, ll c) -> ll { return dir + 2 * (r + H * c); };
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];
  ll source = 2*H*W;
  ll sink = 2*H*W + 1;
  mf_graph<ll> graph(2 * H * W + 2);

  const ll big = 1e18;
  vector<ll> top(W);
  REP(i, 0, H) {
    ll left = 0;
    graph.add_edge(source, enc(0, i, 0), 1);
    REP(j, 0, W) {
      if (S[i][j] == '.') {
        if (i == 0) graph.add_edge(enc(1, 0, j), sink, 1);
        graph.add_edge(enc(0, i, left), enc(1, top[j], j), big);
      }else {
        left = j + 1;
        top[j] = i + 1;
        if (j + 1 < W) graph.add_edge(source, enc(0, i, j + 1), 1);
        if (i + 1 < H) graph.add_edge(enc(1, i + 1, j), sink, 1);
      }
    }
  }
  ll f = graph.flow(source, sink);
  cout << f << endl;

  return 0;
}

