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

  ll N; cin >> N;
  vector ans(N + 1, 0LL);
  REP(x, 1, N + 1) {
    if (x * x  > N) break;
    REP(y, 1, N + 1) {
      if (x * x + y * y + x * y > N) break;
      REP(z, 1, N + 1) {
        ll n = x * x + y * y + z * z + x * y + y * z + z * x;
        if (n > N) break;
        ans[n]++;
      }
    }
  }
  REPOUT(i, 1, N + 1, ans[i], "\n");

  return 0;
}

