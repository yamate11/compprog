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
  vector<ll> A(4);
  REP(i, 0, 4) cin >> A[i];
  string ans;
  ll idx = 0;
  REP(i, 0, SIZE(S) + 1) {
    if (idx < 4 and i == A[idx]) {
      ans += "\"";
      idx += 1;
    }
    if (i == SIZE(S)) break;
    ans += S[i];
  }
  cout << ans << endl;


  return 0;
}

