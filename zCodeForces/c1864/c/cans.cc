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

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll X; cin >> X;
    ull cur = X;
    vector<ll> ans;
    ans.push_back(cur);
    while (not has_single_bit(cur)) {
      ll t = countr_zero(cur);
      ll a = rotl(1ULL, t);
      cur -= a;
      ans.push_back(cur);
    }
    while (cur > 1) {
      ans.push_back(cur / 2);
      cur /= 2;
    }
    cout << SIZE(ans) << "\n";
    REPOUT(i, 0, SIZE(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

