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

  string S; cin >> S;
  ll T; cin >> T;
  ll x = 0, y = 0;
  ll d = 0;
  for (char c : S) {
    if (c == 'L') x--;
    else if (c == 'R') x++;
    else if (c == 'U') y++;
    else if (c == 'D') y--;
    else if (c == '?') d++;
    else assert(0);
  }
  ll ans = -1;
  if (T == 1) {
    ans = abs(x) + abs(y) + d;
  }else {
    ans = abs(x) + abs(y) - d;
    if (ans < 0) ans = abs(ans) % 2;
  }
  cout << ans << endl;

  return 0;
}

