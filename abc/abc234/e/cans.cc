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

  string s; cin >> s;
  ll len = SIZE(s);
  string ans;
  REP2(t, s[0] - '0', s[0] - '0' + 2) {
    REP2(d, -9, 10) {
      auto check = [&]() -> void {
        string cand;
        ll x = t;
        REP(i, len) {
          if (x < 0 or 9 < x) return;
          cand += '0' + x;
          x += d;
        }
        if (cand < s) return;
        if (SIZE(ans) > 0 and ans <= cand) return;
        ans = cand;
      };
      check();
    }
  }
  cout << ans << endl;
  return 0;
}

