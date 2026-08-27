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
  ll ans = 0;
  REP(i, 0, N) {
    ll maxlen = min(i, N - i - 1);
    ll cur = 0;
    ll diff = 0;
    REP(k, 0, maxlen + 1) {
      if (S[i - k] != S[i + k]) diff++;
      if (diff >= 2) break;
      cur++;
    }
    ans += cur;
  }
  REP(i, 0, N - 1) {
    ll maxlen = min(i, N - i - 2);
    ll cur = 0;
    ll diff = 0;
    REP(k, 0, maxlen + 1) {
      if (S[i - k] != S[i + 1 + k]) diff++;
      if (diff >= 2) break;
      cur++;
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}

