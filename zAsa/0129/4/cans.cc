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

  ll N; cin >> N;
  vector Z(N, vector<pll>());
  REP(i, 0, N) {
    ll a; cin >> a;
    REP(j, 0, a) {
      ll x, y; cin >> x >> y; x--;
      Z[i].emplace_back(x, y);
    }
  }
  ll ans = 0;
  REP(t, 0, 1LL << N) {
    auto check = [&]() -> bool {
      REP(i, 0, N) {
        if (t >> i & 1) {
          for (auto [x, y] : Z[i]) {
            if ((t >> x & 1) != y) return false;
          }
        }
      }
      return true;
    };
    if (check()) ans = max(ans, (ll)popcount((u64)t));
  }
  cout << ans << endl;
  return 0;
}

