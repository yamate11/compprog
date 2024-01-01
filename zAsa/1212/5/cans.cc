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

#if DEBUG
  ll K1 = 10;
#else
  ll K1 = 50;
#endif  
  ll K2 = 2 * K1;
  ll A, B; cin >> A >> B;

  vector<string> ans(K2);
  REP(i, 0, K1) ans[i] = string(K2, '#');
  REP(i, K1, K2) ans[i] = string(K2, '.');
  ll x = 1, y = 1;
  REP(i, 0, A - 1) {
    ans[x][y] = '.';
    y += 2;
    if (y >= K2) { y = 1; x += 2; }
  }
  x = K1 + 1; y = 1;
  REP(i, 0, B - 1) {
    ans[x][y] = '#';
    y += 2;
    if (y >= K2) { y = 1; x += 2; }
  }
  cout << K2 << " " << K2 << endl;
  REP(i, 0, K2) cout << ans[i] << "\n";

  return 0;
}

