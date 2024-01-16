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

  string S; cin >> S;
  ll N = SIZE(S);
  S += ".";
  ll ans = 0;
  ll i = N;
  while (true) {
    ll j = i;
    for (; j >= 1 and S[j - 1] != S[j]; j--);
    if (j == 0) break;
    ll x = 0;
    REP(k, j + 1, i) if (S[k] != S[j]) x++;
    if (S[j] != S[i]) x += N - i;
    ans += x;
    for (i = j; i >= 1 and S[i - 1] == S[j]; i--);
    if (i == 0) break;
  }
  cout << ans << endl;

  return 0;
}

