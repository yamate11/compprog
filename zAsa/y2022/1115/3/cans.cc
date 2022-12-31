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

  ll N; cin >> N;
  ll lmax = -100;
  ll rmin = 1e10;
  REP(i, 0, N) {
    ll l, r; cin >> l >> r;
    rmin = min(rmin, r);
    lmax = max(lmax, l);
    if (lmax <= rmin) {
      cout << 0 << "\n";
    }else {
      cout << (lmax - rmin + 1) / 2 << "\n";
    }
  }

  return 0;
}

