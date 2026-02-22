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
    ll N; cin >> N;
    // @InpVec(N, R, dec=1) [OEAHwEWc]
    auto R = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; R[i] = v; }
    // @End [OEAHwEWc]

    vector vec(N, vector<ll>());
    REP(i, 0, N) vec[R[i]].push_back(i);
    ll ans = 0;
    REP(r, 0, N) {
      for (ll i : vec[r]) {
        if (R[i] == r) {
          if (i + 1 < N and R[i + 1] > r + 1) {
            ans += R[i + 1] - (r + 1);
            R[i + 1] = r + 1;
            vec[r + 1].push_back(i + 1);
          }
          if (i - 1 >= 0 and R[i - 1] > r + 1) {
            ans += R[i - 1] - (r + 1);
            R[i - 1] = r + 1;
            vec[r + 1].push_back(i - 1);
          }
        }
      }
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

