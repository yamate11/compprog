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
  ll ans = 0;
  for (ll i = 0; i < N; ) {
    if (S[i] == S[i + 1]) {
      ll j;
      for (j = i + 2; j < N; j++) {
        if (S[i] != S[j]) break;
      }
      ll k = j - i;
      ans += k * (k - 1) / 2;
      i = j;
    }else {
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}

