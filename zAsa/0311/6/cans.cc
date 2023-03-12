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
  string S; cin >> S;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll K; cin >> K;
    ll nD = 0, nM = 0, nDM = 0;
    ll ans = 0;
    REP(i, 0, N) {
      if (i >= K) {
        if (S[i - K] == 'D') {
          nD--;
          nDM -= nM;
        }else if (S[i - K] == 'M') {
          nM--;
        }else if (S[i - K] == 'C') {
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

