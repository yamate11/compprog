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
    ll N, X; cin >> N >> X;
    vector A(3, vector<ll>(N, 0LL));
    REP(i, 0, 3) REP(j, 0, N) {
      cin >> A[i][j];
    }
    ll t = 0;
    REP(i, 0, 3) {
      REP(j, 0, N) {
        if ((A[i][j] & X) == A[i][j]) t |= A[i][j];
        else break;
      }
    }
    cout << (X == t ? "Yes\n" : "No\n");

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

