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

  ll D; cin >> D;
  ll ans = D + 1;
  for (ll x = 0; x * x <= D; x++) {
    ll y = llround(sqrt((long double)(D - x * x)));
    REP(z, y - 3, y + 4)  {
      if (z >= 0) {
        ans = min(ans, abs(x * x + z * z - D));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

