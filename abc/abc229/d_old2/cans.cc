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
  ll K; cin >> K;
  ll N = SIZE(S);
  ll p = 0;
  ll k = 0;
  ll ans = 0;
  REP(q, 0, N) {
    while (p < N and (k < K or S[p] == 'X')) if (S[p++] == '.') k++;
    ans = max(ans, p - q);
    if (S[q] == '.') k--;
    if (q == N) break;
    if (p < q) {
      p = q;
      k = 0;
    }
  }
  cout << ans << endl;

  return 0;
}

