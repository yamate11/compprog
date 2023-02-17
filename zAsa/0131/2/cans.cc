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

  ll N; cin >> N;
  string S, T; cin >> S >> T;
  ll cnt = 0;
  REP(i, 0, N) if (S[i] != T[i]) cnt++;
  if (cnt % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll m = cnt / 2;
  ll p = 0;
  ll q = 0;
  REP(i, 0, N) {
    if (S[i] == T[i]) {
      cout << '0';
    }else {
      if (p < m and q < m) {
        cout << '0';
        if ('0' != S[i]) p++;
        if ('0' != T[i]) q++;
      }else if (p == m) {
        cout << S[i];
      }else if (q == m) {
        cout << T[i];
      }
    }
  }
  cout << endl;
  return 0;
}

