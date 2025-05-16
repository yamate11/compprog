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

  auto solve = [&]() -> ll {
    ll N, K; cin >> N >> K;
    vector tbl_init(2, vector(2, vector(2, vector(2*K + 1, -1LL))));
    auto tbl = tbl_init;
    REP(i, 0, N) {
      auto prev = move(tbl);
      tbl = tbl_init;
      ll x, y, z; cin >> x >> y >> z;
      REP(bx, 0, 2) REP(by, 0, 2) REP(bz, 0, 2) {
        
      }
    }
  };

  ll T; cin >> T;
  REP(t, 0, T) {
    cout << solve() << "\n";
  }

  return 0;
}

