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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = SIZE(S);
  ll ans = -1;
  if (N % 2 == 0) {
    ll p = N / 2;
    if (S[p - 1] != S[p]) ans = p;
    ll i = 0;
    for (; p + i < N and S[p - 1 - i] == S[p + i] and S[p] == S[p + i]; i++);
    ans = p + i;
  }else {
    ll p = N / 2;
    ll i = 0;
    for (; p + i < N and S[p - i] == S[p + i] and S[p] == S[p + i]; i++);
    ans = (N + 1) / 2 + i - 1;
  }
  cout << ans << endl;

  return 0;
}

