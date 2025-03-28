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

  ll N, G, E; cin >> N >> G >> E;
  // @InpVec(G, P) [Lh0sxRIE]
  auto P = vector(G, ll());
  for (int i = 0; i < G; i++) { ll v; cin >> v; P[i] = v; }
  // @End [Lh0sxRIE]
  // @InpMVec(E, (A, B)) [684WSZCF]
  auto A = vector(E, ll());
  auto B = vector(E, ll());
  for (int i = 0; i < E; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [684WSZCF]

  mf_graph<ll> gr(N + 1);
  REP(i, 0, E) {
    if (A[i] == 0) gr.add_edge(A[i], B[i], 1);
    else if (B[i] == 0) gr.add_edge(B[i], A[i], 1);
    else {
      gr.add_edge(A[i], B[i], 1);
      gr.add_edge(B[i], A[i], 1);
    }
  }
  REP(i, 0, G) gr.add_edge(P[i], N, 1);
  ll ans = gr.flow(0, N);
  cout << ans << endl;

  return 0;
}

