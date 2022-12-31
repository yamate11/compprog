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
  ll N = SIZE(S);
  const ll big = 1000;
  ll ans = big;
  REP(x, 1, 1LL << N) {
    ll t = 0;
    REP(i, 0, N) if (x >> i & 1) t += S[i] - '0';
    if (t % 3 == 0) ans = min(ans, N - __builtin_popcountll(x));
  }
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

