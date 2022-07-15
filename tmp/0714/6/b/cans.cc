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

  string S; cin >> S;
  ll N = SIZE(S);
  ll ans = N;
  if (N % 2 == 0) {
    ll h = N / 2;
    REP(i, h) {
      if (S[h + i - 1] != S[h + i] or S[h - i - 1] != S[h - i]) {
        ans = h + i;
        break;
      }
    }
  }else {
    ll h = N / 2;
    REP(i, h) {
      if (S[h + i] != S[h + i + 1] or S[h - i - 1] != S[h - i] ) {
        ans = h + i + 1;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

