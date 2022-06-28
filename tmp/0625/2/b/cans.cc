#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S, T; cin >> S >> T;
  ll ns = SIZE(S), nt = SIZE(T);
  ll ans = 1e18;
  REP(i, ns - nt + 1) {
    ll cnt = 0;
    REP(j, nt) if (T[j] != S[i + j]) cnt++;
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

