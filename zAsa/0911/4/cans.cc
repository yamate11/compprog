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

  ll lim = 1e9;

  auto solve = [&]() -> tuple<ll, ll, ll, ll> {
    ll S; cin >> S;
    if (S == lim * lim) return {lim, 0, 0, lim};
    ll p = S / lim;
    ll q = S % lim;
    if (q == 0) return {p, 0, 0, lim};
    return {p + 1, 1, lim - q, lim};
  };
  auto [c, d, e, f] = solve();
  cout << "0 0 " << c << " " << d << " " << e << " " << f << "\n";

}

