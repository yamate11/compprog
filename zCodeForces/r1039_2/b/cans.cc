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
    // @InpVec(n, p) [JqJH7yej]
    auto p = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; p[i] = v; }
    // @End [JqJH7yej]
    string ans = "L";
    ll prev = p[0];
    REP(i, 1, n) {
      ll j = n - i;
      if (i < j) {
        if (p[i] < p[j]) {
          if (prev < p[i]) {
            ans += "RL";
            prev = p[i];
          }else {
            ans += "LR";
            prev = p[j];
          }
        }else {
          if (prev < p[j]) {
            ans += "LR";
            prev = p[j];
          }else {
            ans += "RL";
            prev = p[i];
          }
        }
      }else if (i == j) {
        ans += "L";
        break;
      }else {
        break;
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

