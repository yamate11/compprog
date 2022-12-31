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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [1NstSlGH]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [1NstSlGH]
  vector<ll> cls(N, -1LL);
  auto dfs = [&](auto rF, ll nd, ll c) -> void {
    if (cls[nd] == -1) {
      cls[nd] = c;
      for (ll v : nbr[nd]) rF(rF, v, 1 - c);
    }else if (cls[nd] != c) {
      throw myexc();
    }
  };
  try {
    dfs(dfs, 0, 0);
  }catch (myexc& e) {
    cout << N * (N - 1) / 2 - M << endl;
    return 0;
  }
  ll m0 = 0, m1 = 0;
  REP(i, 0, N) {
    if (cls[i] == 0) m0++;
    else m1++;
  }
  cout << m0 * m1 - M << endl;

  return 0;
}

