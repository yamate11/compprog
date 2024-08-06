#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  auto solve = [&]() -> bool {
    ll N, M; cin >> N >> M;
    // @InpMVec(M, ((U, dec=1), (V, dec=1))) [1yG3xhvn]
    auto U = vector(M, ll());
    auto V = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; U[i] = v1;
      ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    }
    // @End [1yG3xhvn]
    vector nbr(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u = U[i];
      int v = V[i];
      if (not (0 <= u and u < N)) return false;
      if (not (0 <= v and v < N)) return false;
      nbr[u].emplace_back(v);
      nbr[v].emplace_back(u);
    }
    // @End [JVFsgFEN]

    vector<ll> conn(N, false);
    REP(u, 0, N) {
      for (ll v : nbr[u]) {
        if (u == v) return false;
        if (conn[v]) return false;
        conn[v] = true;
      }
      for (ll v : nbr[u]) conn[v] = false;
    }
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

