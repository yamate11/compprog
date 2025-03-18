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

  ll N, M; cin >> N >> M;
  bool found = false;
  ll ans = -1;
  REP(a, 1, N + 1) {
    ll b;
    if (M % a == 0) b = M / a;
    else b = M / a + 1;
    if (b <= N) {
      if (not found) {
        found = true;
        ans = a * b;
      }else {
        ans = min(ans, a * b);
      }
    }
    if (b < a) break;
  }
  if (not found) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}

