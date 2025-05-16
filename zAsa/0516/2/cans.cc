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

  vector<bool> vec(10);
  REP(i, 0, 6) {
    ll e; cin >> e;
    vec[e] = true;
  }
  ll B; cin >> B;
  bool b = false;
  ll m = 0;
  REP(i, 0, 6) {
    ll x; cin >> x;
    if (vec[x]) m++;
    if (x == B) b = true;
  }
  ll ans = 0;
  if (m == 6) ans = 1;
  else if (m == 5 and b) ans = 2;
  else if (m == 5) ans = 3;
  else if (m == 4) ans = 4;
  else if (m == 3) ans = 5;
  else ans = 0;
  cout << ans << endl;

  return 0;
}

