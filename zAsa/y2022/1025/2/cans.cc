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

  auto dec = [&](ll e) -> pll {
    if (e == 1) return {3, 3};
    if (e <= 3) return {2, 2 + (e - 2) * 2};
    if (e <= 6) return {1, 1 + (e - 4) * 2};
    if (e <= 10) return {0, 0 + (e - 7) * 2};
    assert(0);
  };

  vector A(4, vector(7, ' '));
  ll a, b; cin >> a >> b;
  vector<char> res(11, 'x');
  REP(i, 0, a) {
    ll e; cin >> e;
    if (e == 0) e = 10;
    res[e] = '.';
  }
  REP(i, 0, b) {
    ll e; cin >> e;
    if (e == 0) e = 10;
    res[e] = 'o';
  }
  REP(i, 1, 11) {
    auto [x, y] = dec(i);
    A[x][y] = res[i];
  }
  REP(i, 0, 4) {
    REP(j, 0, 7) cout << A[i][j];
    cout << "\n";
  }
  

  return 0;
}

