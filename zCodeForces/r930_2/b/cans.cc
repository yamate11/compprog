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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector A(2, string());
    REP(i, 0, 2) cin >> A[i];
    auto f = [&](auto rF, ll i) -> pair<ll, ll> {
      ll j = i;
      while (j + 1 < N and A[1][j] == A[0][j + 1]) j++;
      if (j + 1 < N) {
        if (A[1][j] == '1') {
          return rF(rF, j + 1);
        }else {
          return pll(i, j);
        }
      }else {
        return pll(i, N - 1);
      }
    };
    auto [xx, yy] = f(f, 0);
    cout << A[0].substr(0, xx + 1) << A[1].substr(xx) << "\n";
    cout << yy - xx + 1 << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

