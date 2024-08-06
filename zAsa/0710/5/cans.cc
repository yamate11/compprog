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

  ll A, B; cin >> A >> B;
  ll H = 100;
  ll W = 100;
  ll half = H / 2;
  vector brd(H, string(W, ' '));
  REP(i, 0, H) REP(j, 0, W) brd[i][j] = i < half ? '#' : '.';
  A--; B--;
  REP(i, 0, half) {
    if (i % 2 != 0) {
      REP(j, 0, W) {
        if (j % 2 != 0 and A > 0) {
          brd[i][j] = '.';
          A--;
        }
      }
    }
  }
  REP(i, half, H) {
    if (i % 2 != 0) {
      REP(j, 0, W) {
        if (j % 2 != 0 and B > 0) {
          brd[i][j] = '#';
          B--;
        }
      }
    }
  }
  cout << H << " " << W << "\n";
  REP(i, 0, H) cout << brd[i] << "\n";

  return 0;
}

