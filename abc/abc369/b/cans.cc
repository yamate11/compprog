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

  ll l = -1;
  ll r = -1;
  ll N; cin >> N;
  ll ans = 0;
  REP(i, 0, N) {
    ll a; cin >> a;
    char s; cin >> s;
    if (s == 'L') {
      if (l < 0) l = a;
      else {
        ans += abs(l - a);
        l = a;
      }
    }else {
      if (r < 0) r = a;
      else {
        ans += abs(r - a);
        r = a;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
