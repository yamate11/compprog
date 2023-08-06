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

  ll N, K; cin >> N >> K;
  ll x = K;
  while (x % 10 == 0) x /= 10;
  if (x < K) {
    cout << 0 << endl;
    return 0;
  }
  string s = to_string(x);
  reverse(ALL(s));
  ll y = stoll(s);
  if (y < x) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  ll x0 = x;
  while (x <= N) {
    ans++;
    x *= 10;
  }
  if (y != x0) {
    while (y <= N) {
      ans++;
      y *= 10;
    }
  }
  cout << ans << endl;
  return 0;
}

