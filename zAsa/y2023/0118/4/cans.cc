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
  ll T; cin >> T;
  ll x = 0, y = 0, z = 0;
  for (char c : S) {
    if (c == 'L') {
      x--;
    }else if (c == 'R') {
      x++;
    }else if (c == 'U') {
      y++;
    }else if (c == 'D') {
      y--;
    }else if (c == '?') {
      z++;
    }else assert(0);
  }
  ll d = abs(x) + abs(y);
  if (T == 1) {
    cout << d + z << endl;
  }else {
    if (z < d) {
      cout << d - z << endl;
    }else if ((z - d) % 2 == 0) {
      cout << 0 << endl;
    }else {
      cout << 1 << endl;
    }
  }

  return 0;
}

