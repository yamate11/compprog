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

int main() {
  ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  
  double rmax = -1.0;
  ll ans_sol = -1;
  ll ans_sug = -1;
  for (ll a = 0; true; a++) {
    ll watA = 100 * a * A;
    if (watA > F) break;
    for (ll b = 0; true; b++) {
      ll watB = watA + 100 * b * B;
      if (watB > F) break;
      for (ll c = 0; true; c++) {
        ll sugC = c * C;
        ll solC = watB + sugC;
        if (solC > F) break;
        for (ll d = 0; true; d++) {
          ll sugD = sugC + d * D;
          ll solD = watB + sugD;
          if (solD > F) break;
          if (0 < solD and sugD <= watB / 100 * E) {
            double r = (double)sugD / solD;
            if (r > rmax) {
              rmax = r;
              ans_sol = solD;
              ans_sug = sugD;
            }
          }
        }
      }
    }
  }
  cout << ans_sol << " " << ans_sug << endl;

  return 0;
}

