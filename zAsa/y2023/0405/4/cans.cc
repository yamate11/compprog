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

  vector<string> vec{"dream", "dreamer", "erase", "eraser"};
  string S; cin >> S;
  ll k = SIZE(S);
  while (k > 0) {
    if (not [&]() -> bool {
      REP(i, 0, 4) {
        ll t = SIZE(vec[i]);
        if (k >= t and S.substr(k - t, t) == vec[i]) {
          k -= t;
          return true;
        }
      }
      return false;
    }()) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}

