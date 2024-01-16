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

  ll N; cin >> N;
  // @InpNbrList(N, N - 1, nbr, dec=1) [zvgN135y]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [zvgN135y]
  vector L(N, 0LL);
  vector R(N, 0LL);
  auto f = [&](auto rF, ll nd, ll pt, ll seq) -> ll {
    L[nd] = seq;
    bool first = true;
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      if (first) first = false;
      else seq++;
      seq = rF(rF, c, nd, seq);
    }
    R[nd] = seq;
    return seq;
  };
  f(f, 0, -1, 1);
  REP(i, 0, N) {
    cout << L[i] << " " << R[i] << "\n";
  }

  return 0;
}

