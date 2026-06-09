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

  auto solve = [&]() -> void {
    ll n; cin >> n;
    using sta = tuple<ll, ll, ll>;
    vector<sta> ans;
    REP(i, 2, n + 1) ans.emplace_back(i, 1, i);
    REP(i, 1, n - 1) ans.emplace_back(i, i + 1, n);
    cout << ssize(ans) << "\n";
    for (auto [i, l, r] : ans) cout << i << " " << l << " " << r << "\n";
  };
  


  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

