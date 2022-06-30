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

  ll N; cin >> N;
  string S; cin >> S;
  ll Q; cin >> Q;
  REP (_q, Q) {
    ll K; cin >> K;
    ll nD = 0, nM = 0, nDM = 0;
    ll ans = 0;
    REP(i, N) {
      if (i - K >= 0) {
        if (S[i - K] == 'D') {
          nD--;
          nDM -= nM;
        }else if (S[i - K] == 'M') {
          nM--;
        }
      }
      if (S[i] == 'D') {
        nD++;
      }else if (S[i] == 'M') {
        nM++;
        nDM += nD;
      }else if (S[i] == 'C') {
        ans += nDM;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}

