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

  vector<pll> nbr4{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  ll M, N; cin >> M >> N;
  // @InpGrid(M, N, A) [SdLLurXb]
  auto A = vector(M, vector(N, ll()));
  for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [SdLLurXb]
  // @InpGrid(M, N, B) [SOQUG8jc]
  auto B = vector(M, vector(N, ll()));
  for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; B[i][j] = v; }
  // @End [SOQUG8jc]
  // auto enc = [&](ll r, ll c) -> ll { return r * N + c; };
  vector C(M, vector(N, 0LL));
  ll num1 = 0, num2 = 0;
  REP(i, 0, M) REP(j, 0, N) {
    if (A[i][j] == B[i][j]) C[i][j] = 0;
    else if (B[i][j] == 0) {
      C[i][j] = 1;
      num1++;
    }else {
      C[i][j] = 2;
      num2++;
    }
  }
  ll source = 0, sink = 1;
  mf_graph<ll> graph(2 + num1 + num2);
  vector gnode(M, vector(N, -1LL));
  ll seq = 2;
  REP(i, 0, M) REP(j, 0, N) {
    if (C[i][j] == 1) {
      gnode[i][j] = seq++;
      graph.add_edge(source, gnode[i][j], 1);
    }else if (C[i][j] == 2) {
      gnode[i][j] = seq++;
      graph.add_edge(gnode[i][j], sink, 1);
    }
  }
  REP(i, 0, M) REP(j, 0, N) {
    if (C[i][j] == 1) {
      for (pll d : nbr4) {
        ll i0 = i + d.first;
        ll j0 = j + d.second;
        if (0 <= i0 and i0 < M and 0 <= j0 and j0 < N and C[i0][j0] == 2) {
          graph.add_edge(gnode[i][j], gnode[i0][j0], 1);
        }
      }
    }
  }
  ll h = graph.flow(source, sink);
  cout << num1 + num2 - h << endl;

  return 0;
}

