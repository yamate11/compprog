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

  ll N, S, M, L; cin >> N >> S >> M >> L;
  
  ll ans = 1e18;
  REP(i, 0, N + 1) {
    REP(j, 0, N + 1) {
      REP(k, 0, N + 1) {
        if (6 * i + 8 * j + 12 * k >= N) {
          ll v = S * i + M * j + L * k;
          ans = min(ans, v);
        }
        if (6 * i + 8 * j + 12 * k >= N) break;
      }
      if (6 * i + 8 * j >= N) break;
    }
    if (6 * i >= N) break;
  }
  cout << ans << endl;
  return 0;
}

