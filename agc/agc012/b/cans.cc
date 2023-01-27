#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [YtKad084]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [YtKad084]
  vector ans(N, -1LL);
  vector H(N, vector<pll>());
  vector rec(N, vector<ll>(11));
  ll Q; cin >> Q;
  vector C(N, -1LL);
  vector D(N, -1LL);
  vector V(Q, -1LL);

  auto put = 

  REP(q, 0, Q) {
    ll v, d, c; cin >> v >> d >> c; v--;
    V[q] = v;
    C[v] = c;
    D[v] = d;
    put(v, d);
  }
  REPrev(q, Q - 1, 0) {
    n = V[q];
    for (auto [m, _d] : H(n)) {
      if (ans[m] < 0) {
        REP(d, 1, 11) {
          if (rec[d] >= 0) {
            for (ll p : nbr[m]) put(rec[d], d - 1);
          }
        }
      }
    }
  }

  return 0;
}

