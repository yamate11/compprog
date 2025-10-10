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
  // @InpVec(N, A) [cs8FJVE3]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [cs8FJVE3]
  // @InpMVec(M, ((L, dec=1), (R, dec=0))) [OYjhmVUb]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
  }
  // @End [OYjhmVUb]

  ll big = 1e9;
  mcf_graph<ll, ll> g(N + 3);
  ll source = N + 1;
  ll sink = N + 2;
  REP(i, 0, M) {
    g.add_edge(L[i], R[i], big, 1);
  }
  ll f0 = 0;
  REP(i, 0, N - 1) {
    if (A[i] > A[i + 1]) {
      f0 += A[i] - A[i + 1];
      g.add_edge(source, i + 1, A[i] - A[i + 1], 0);
    }
    if (A[i] < A[i + 1]) g.add_edge(i + 1, sink, A[i + 1] - A[i], 0);
  }
  g.add_edge(N, sink, big, 0);
  auto [f, c] = g.flow(source, sink);
  if (f < f0) {
    cout << -1 << endl;
  }else {
    cout << c << endl;
  }

  return 0;
}

