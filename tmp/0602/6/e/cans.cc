#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  using pll = pair<ll, ll>;
  vector cons(N + 1, vector<pll>());
  REP(i, M) {
    ll x, y, z; cin >> x >> y >> z;
    cons[x].emplace_back(y, z);
  }
  vector tbl_init(1LL << N, 0LL);
  auto tbl = tbl_init;
  tbl[0] = 1;
  REP(i, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(x, 1LL << N) {
      if (prev[x] == 0) continue;
      REP(j, N) {
        if (x >> j & 1) continue;
        ll xx = x | (1LL << j);
        if ([&]() {
          for (auto [y, z] : cons[i]) {
            ll p = __builtin_popcountll(xx & ((1LL << y) - 1));
            if (p > z) return false;
          }
          return true;
        }()) tbl[xx] += prev[x];
      }
    }
  }
  cout << tbl[(1LL << N) - 1] << endl;

  return 0;
}

