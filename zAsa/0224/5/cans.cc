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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    ll M = 1LL << N;
    // @InpVec(M, P) [zPPqykud]
    auto P = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
    // @End [zPPqykud]

    vector<pll> B(M);
    REP(i, 1, M / 2) B[i] = pll(2 * i, 2 * i + 1);
    REP(i, M / 2, M) B[i] = pll(P[2 * i - M], P[2 * i + 1 - M]);
    
    auto f = [&](auto rF, ll nd) -> ll {
      auto [i, j] = B[nd];
      if (nd >= M / 2) {
        if (i > j) B[nd] = pll(j, i);
        return min(i, j);
      }else {
        ll x = rF(rF, i);
        ll y = rF(rF, j);
        if (x > y) B[nd] = pll(j, i);
        return min(x, y);
      }
    };

    f(f, 1);

    auto g = [&](auto rF, ll nd) -> void {
      auto [i, j] = B[nd];
      if (nd >= M / 2) {
        cout << i << " " << j << " ";
      }else {
        rF(rF, i);
        rF(rF, j);
      }
    };
    g(g, 1);
    cout << endl;

    

  };



  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

