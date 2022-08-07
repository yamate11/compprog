#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  auto solve = [&]() -> bool {
    string S; cin >> S;
    ll N = SIZE(S);
    assert(N % 2 == 0);
    ll p = 0, q = 0, x = 0;
    REP(i, N) {
      if (S[i] == '(') p++;
      else if (S[i] == ')') q++;
      else if (S[i] == '?') x++;
      else assert(0);
    }
    ll xp = N / 2 - p;
    ll xq = N / 2 - q;
    assert(xp + xq == x);
    if (xp == 0 or xq == 0) return true;
    ll v = 0;
    bool crit = false;
    REP(i, N) {
      if (S[i] == '(') v++;
      else if (S[i] == ')') v--;
      else if (xp > 0) {
        v++;
        xp--;
        if (xp == 0) crit = true;
      }else {
        return false;
      }
      if (crit and v <= 1) return true;
    }
    assert(0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

