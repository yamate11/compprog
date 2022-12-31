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

  ll N; cin >> N;
  string S; cin >> S;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll K; cin >> K;
    ll numD = 0;
    ll numM = 0;
    ll numDM = 0;
    ll ans = 0;
    REP(i, 0, N) {
      if (i >= K) {
        ll j = i - K;
        if (S[j] == 'D') {
          numD--;
          numDM -= numM;
        }else if (S[j] == 'M') {
          numM--;
        }
      }
      if (S[i] == 'C') {
        ans += numDM;
      }
      if (S[i] == 'D') {
        numD++;
      }else if (S[i] == 'M') {
        numM++;
        numDM += numD;
      }
    }
    cout << ans << "\n";
    
  }

  return 0;
}

