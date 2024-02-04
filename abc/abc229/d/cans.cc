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

  string S; cin >> S;
  ll N = SIZE(S);
  ll K; cin >> K;
  ll i = 0;
  ll j = 0;
  ll cnt = 0;
  ll ans = 0;
  while (true) {
    if (cnt <= K) {
      ans = max(ans, j - i);
      if (j == N) break;
      if (S[j] == '.') cnt++;
      j++;
    }else {
      if (S[i] == '.') cnt--;
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}

