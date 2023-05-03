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
  ll ans = 0;
  if (N < 1000) {
    cout << 0 << endl;
    return 0;
  }
  ll x = 1000;
  ll p = 3;
  ll c = 1;
  while (x * 10 - 1 <= N) {
    ans += (x * 10 - x) * c;
    x *= 10;
    p += 1;
    if (p % 3 == 0) c++;
  }
  ans += (N - x + 1) * c;
  cout << ans << endl;

  return 0;
}

