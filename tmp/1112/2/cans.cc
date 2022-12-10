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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // @InpVec(4, T, type=(char, ll), dec='0') [GBTvMG8F]
  auto T = vector(4, ll());
  for (int i = 0; i < 4; i++) { char v; cin >> v; v -= '0'; T[i] = v; }
  // @End [GBTvMG8F]
  REP(x, 0, 8) {
    ll y = T[0];
    REP(i, 0, 3) {
      if (x >> i & 1) y += T[i + 1];
      else y -= T[i + 1];
    }
    if (y == 7) {
      cout << T[0];
      REP(i, 0, 3) {
        if (x >> i & 1) cout << "+";
        else cout << "-";
        cout << T[i + 1];
      }
      cout << "=7\n";
      return 0;
    }
  }

  return 0;
}

