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
  auto chk = [&](ll i) -> ll {
    ll ret = 0;
    while (true) {
      if (i + 1 < N and S[i] == '2' and S[i + 1] == '5') {
        i += 2;
        ret++;
      }else {
        return ret;
      }
    }
  };
  ll i = 0;
  ll ans = 0;
  while (i < N) {
    ll x = chk(i);
    if (x == 0) {
      i++;
    }else {
      i += 2 * x;
      ans += x * (x + 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}

