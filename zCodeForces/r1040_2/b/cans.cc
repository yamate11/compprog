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
    ll n, s; cin >> n >> s;
    // @InpVec(n, a) [iPS0h9Jk]
    auto a = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; a[i] = v; }
    // @End [iPS0h9Jk]
    ll t = accumulate(ALL(a), 0LL);
    if (s <= t - 1 or s == t + 1) {
      ll c0 = 0, c1 = 0, c2 = 0;
      REP(i, 0, n) {
        if (a[i] == 0) c0++;
        else if (a[i] == 1) c1++;
        else c2++;
      }
      vector<ll> ans;
      REP(i, 0, c0) ans.push_back(0);
      REP(i, 0, c2) ans.push_back(2);
      REP(i, 0, c1) ans.push_back(1);
      REPOUT(i, 0, n, ans[i], " ");
    }else {
      cout << -1 << "\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

