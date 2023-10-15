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

  auto judge = [&]() -> bool {

    using sta = pair<char, ll>;
    auto rlc = [&](string s) -> vector<sta> {
      ll n = SIZE(s);
      auto ret = vector<sta>();
      ll cnt = 0;
      REP(i, 0, n + 1) {
        if (0 < i and i < n) {
          if (s[i - 1] != s[i]) {
            ret.emplace_back(s[i - 1], cnt);
            cnt = 1;
          }else {
            cnt++;
          }
        }else if (i == 0) {
          cnt = 1;
        }else if (i == n) {
          ret.emplace_back(s[i - 1], cnt);
          break;
        }else assert(0);
      }
      return ret;
    };

    string S, T; cin >> S >> T;
    auto vs = rlc(S);
    auto vt = rlc(T);
    if (SIZE(vs) != SIZE(vt)) return false;
    REP(i, 0, SIZE(vs)) {
      auto [cs, ls] = vs[i];
      auto [ct, lt] = vt[i];
      if (cs != ct) return false;
      if (ls == lt) continue;
      if (ls >= 2 and ls <= lt) continue;
      return false;
    }
    return true;

  };

  cout << (judge() ? "Yes\n" : "No\n");

  return 0;
}

