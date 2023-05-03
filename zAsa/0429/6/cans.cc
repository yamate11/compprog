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

  auto solve = [&](ll M, ll N) -> ll {

    vector vec(M, vector(N, 0LL));
    auto f = [&](auto rF, ll m, ll n) -> ll {
      if (m == M) return 1;
      if (n == N) return rF(rF, m + 1, 0);

      auto chk = [&](ll face, ll dist) -> bool {
        return (m - dist < 0 or vec[m - dist][n] != face) and
          (n - dist < 0 or vec[m][n - dist] != face);
      };

      auto dotry = [&](ll face) -> ll {
        vec[m][n] = face;
        ll ret = rF(rF, m, n + 1);
        vec[m][n] = 0;
        return ret;
      };

      ll ret = 0;
      if (chk(1, 1)) ret += dotry(1);
      if (chk(2, 1) and chk(2, 2)) ret += dotry(2);
      if (chk(3, 1) and chk(3, 2) and chk(3, 3)) ret += dotry(3);
      return ret;
    };

    return f(f, 0, 0);
  };

  ll m, n; cin >> m >> n;
  if (m >= 8) m = 8 + (m % 4);
  if (n >= 8) n = 8 + (n % 4);
  cout << solve(m, n) << endl;


  return 0;
}

