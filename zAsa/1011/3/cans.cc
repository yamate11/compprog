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

  ll k, a, b; cin >> k >> a >> b;
  ll ans;
  if (b - a <= 2) {
    ans = 1 + k;
  }else {
    if (a - 1 + 2 <= k) {
      ll rem = k - (a - 1);
      ll p = rem / 2;
      ll q = rem % 2;
      ans = a + (b - a) * p + q;
    }else {
      ans = 1 + k;
    }
  }
  cout << ans << endl;
  return 0;
}

