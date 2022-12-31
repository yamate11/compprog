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

  string S, T; cin >> S >> T;
  ll N = SIZE(S);
  ll M = SIZE(T);
  ll ans = 1e9;
  REP(i, 0, N) {
    ll cnt = 0;
    REP(j, 0, M) {
      if (i + j >= N) cnt = 1e9;
      else if (S[i + j] != T[j]) cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

