#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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
  string T; cin >> T;
  ll ans = 0;
  ll zero, one;
  if (T[0] == '0') {
    zero = 1;
    one = 0;
    ans = 0;
  }else {
    zero = 0;
    one = 1;
    ans = 1;
  }
  REP(i, 1, N) {
    ll prev_zero = zero;
    ll prev_one = one;
    if (T[i] == '0') {
      zero = prev_one + 1;
      one = prev_zero;
    }else {
      zero = prev_zero;
      one = prev_one + 1;
    }
    ans += one;
  }
  cout << ans << endl;
  return 0;
}

