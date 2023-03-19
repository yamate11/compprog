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

  auto f = [&](string a) -> vector<ll> {
    vector<ll> ret;
    REP(j, 0, 3) {
      string b = a;
      REP(i, 0, 10) {
        if (j == 0 and i == 0) continue;
        b[j] = (char)('0' + i);
        ret.push_back(stoll(b));
      }
    }
    return ret;
  };

  string A, B; cin >> A >> B;
  ll ans = LLONG_MIN;
  auto v = f(A);
  for (ll x : v) ans = max(ans, x - stoll(B));
  auto w = f(B);
  for (ll x : w) ans = max(ans, stoll(A) - x);
  cout << ans << endl;

  return 0;
}

