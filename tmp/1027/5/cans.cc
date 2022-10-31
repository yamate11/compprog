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

  string S; cin >> S;
  ll N = SIZE(S);
  vector<ll> D(N);
  REP(i, 0, N) D[i] = S[i] - '0';

  vector tbl_init(2, pll(0, 0));
  auto tbl = tbl_init;
  tbl[1] = pll(1, 0);
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(eq, 0, 2) {
      auto [n, c] = prev[eq];
      if (n == 0 and c == 0) continue;
      REP(x, 0, 10) {
        if (eq && x > D[i]) continue;
        ll new_eq = eq && x == D[i];
        if (new_eq) tbl[1] = pll(1, c + (x == 1 ? 1 : 0));
        else  {
          auto [nn, cc] = tbl[0];
          tbl[0] = pll(nn + n, cc + c + (x == 1 ? 1 : 0) * n);
        }
      }
    }
  }
  cout << tbl[0].second + tbl[1].second << endl;

  return 0;
}

