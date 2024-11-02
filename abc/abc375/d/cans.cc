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

  string S; cin >> S;
  ll N = ssize(S);
  vector cntL(26, 0LL);
  vector cntR(26, 0LL);
  REP(i, 1, N) cntR[S[i] - 'A']++;
  ll ans = 0;
  REP(i, 0, N) {
    REP(c, 0, 26) ans += cntL[c] * cntR[c];
    cntL[S[i] - 'A']++;
    if (i + 1 < N) cntR[S[i + 1] - 'A']--;
  }
  cout << ans << endl;

  return 0;
}

