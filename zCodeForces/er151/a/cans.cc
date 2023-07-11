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
    ll n, k, x; cin >> n >> k >> x;
    if (x != 1) {
      cout << "YES\n";
      cout << n << "\n";
      REPOUT(i, 0, n, 1, " ");
    }else if (k == 1) {
      cout << "NO\n";
    }else if (n % 2 == 0) {
      cout << "YES\n";
      cout << n / 2 << "\n";
      REPOUT(i, 0, n / 2, 2, " ");
    }else if (k == 2) {
      cout << "NO\n";
    }else {
      cout << "YES\n";
      ll t = 1 + (n - 3) / 2;
      cout << t << "\n" << 3 << " ";
      REPOUT(i, 0, t - 1, 2, " ");
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

