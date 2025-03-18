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

  ll a, b, c; cin >> a >> b >> c;
  a = a % 10;
  ll ans = -1;
  if (a == 0 or a == 1 or a ==5 or a == 6) ans = a;
  else if (a == 4 or a == 9) {
    if (b % 2 == 0) ans = (a * a) % 10;
    else ans = a;
  }else {
    if (b % 4 == 0) ans = (a * a * a * a) % 10;
    else if (b % 4 == 1) ans = a;
    else if (b % 4 == 2) {
      if (c == 1) ans = (a * a) % 10;
      else ans = (a * a * a * a) % 10;
    }else if (b % 4 == 3) {
      if (c % 2 == 0) ans = a;
      else ans = (a * a * a) % 10;
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

