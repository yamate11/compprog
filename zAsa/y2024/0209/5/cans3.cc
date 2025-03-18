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

  ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  
  double rmax = 0.0;
  ll sol = 100;
  ll sug = 0;
  REP(a, 0, 31) {
    if (100 * a * A > F) break;
    REP(b, 0, 31) {
      if (100 * a * A + 100 * b * B > F) break;
      if (a + b == 0) continue;
      REP(c, 0, 3001) {
        if (100 * a * A + 100 * b * B + c * C > F) break;
        REP(d, 0, 3001) {
          if (100 * a * A + 100 * b * B + c * C + d * D > F) break;
          if (c * C + d * D <= (a * A + b * B) * E) {
            double r = double(c * C + d * D) / (100 * (a * A + b * B) + (c * C + d * D));
            if (r > rmax) {
              rmax = r;
              sug = c * C + d * D;
              sol = 100 * (a * A + b * B) + (c * C + d * D);
            }
          }
        }
      }
    }
  }
  cout << sol << " " << sug << endl;

  return 0;
}

