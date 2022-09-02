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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll n = SIZE(S);
  vector<ll> cnt(3);
  REP(i, 0, n) cnt[(S[i] - '0') % 3]++;
  ll s = (cnt[1] + 2 * cnt[2]) % 3;
  ll ans = -1;
  if (s == 0) ans = 0;
  else if (cnt[s] >= 1) ans = n == 1 ? -1 : 1;
  else ans = n == 2 ? -1 : 2;
  cout << ans << endl;

  return 0;
}

