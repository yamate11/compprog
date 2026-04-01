#include <iostream>
#include <iomanip>
#include <map>
#include <string>
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
  string S; cin >> S;

  auto f = [&](char c1, char c2) -> ll {
    ll cnt1 = 0, cnt2 = 0;
    ll ret = 0;
    REP(i, 0, 2 * N) {
      if (S[i] == c1) {
        cnt1++;
        if (cnt1 <= cnt2) ret += cnt2 - cnt1 + 1;
      }else {
        cnt2++;
        if (cnt1 > cnt2) ret += cnt1 - cnt2;
      }
    }
    return ret;
  };
  ll v1 = f('A', 'B');
  ll v2 = f('B', 'A');
  ll ans = min(v1, v2);
  cout << ans << endl;

  return 0;
}

