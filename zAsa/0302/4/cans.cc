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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, x, y; cin >> N >> x >> y;
  // @InpVec(N, A) [tI1mZOQO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [tI1mZOQO]
  vector<ll> vecX, vecY;
  REP(i, 1, N) {
    if (i % 2 == 0) vecX.push_back(A[i]);
    else vecY.push_back(A[i]);
  }
  auto func = [&](const auto& vec, ll goal) -> bool {
    ll M = SIZE(vec);
    ll tbl_zero = M * 10;
    ll tbl_sz = 2 * tbl_zero + 1;
    vector tbl_init(tbl_sz, false);
    auto tbl = tbl_init;
    tbl[M * 10] = true;
    for (ll v : vec) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(i, 0, tbl_sz) {
        if (prev[i]) {
          if (i + v < tbl_sz) tbl[i + v] = true;
          if (i - v >= 0) tbl[i - v] = true;
        }
      }
    }
    ll idx = tbl_zero + goal;
    return (idx >= 0 and idx < tbl_sz and tbl[idx]);
  };

  bool b1 = func(vecX, x - A[0]);
  bool b2 = func(vecY, y);
  cout << (b1 and b2 ? "Yes\n" : "No\n");

  return 0;
}

