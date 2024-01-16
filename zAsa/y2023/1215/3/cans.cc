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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    string X, Y; cin >> X >> Y;

    auto check = [&](ll p, ll q) -> bool {
      ll xa = 0, xb = 0, xc = 0, ya = 0, yb = 0;
      REP(i, p, q) {
        if (X[i] == 'A') xa++;
        if (X[i] == 'B') xb++;
        if (X[i] == 'C') xc++;
        if (Y[i] == 'A') ya++;
        if (Y[i] == 'B') yb++;
      }
      if (xa > ya or xb > yb) return false;
      REP(i, p, q) {
        if (X[i] == 'C') {
          if (xa < ya) {
            X[i] = 'A';
            xa++;
          }else {
            X[i] = 'B';
            xb++;
          }
        }
      }
      ll diff = 0;
      REP(i, p, q) {
        if (X[i] == 'A' and Y[i] == 'B') diff++;
        if (X[i] == 'B' and Y[i] == 'A') diff--;
        if (diff < 0) return false;
      }
      return true;

    };

    ll p = 0;
    REP(q, 0, N + 1) {
      if (q == N or Y[q] == 'C') {
        if (q < N and X[q] != 'C') return false;
        if (not check(p, q)) return false;
        p = q + 1;
      }
    }
    return true;
  };


  ll T; cin >> T;
  REP(i, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

