#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;
int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<tuple<ll, ll, ll>> LRI;
    REP(i, N) {
      ll l, r; cin >> l >> r;
      LRI.emplace_back(l, r, i);
    }
    sort(ALL(LRI));
    ll t = 1;
    ll idx = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    while (true) {
      while (idx < N) {
        auto [l, r, i] = LRI[idx];
        if (t < l) break;
        pque.emplace(r, i);
        idx++;
      }
      if (not pque.empty()) {
        auto [r, i] = pque.top(); pque.pop();
        if (r < t) {
          cout << "No\n";
          return;
        }
      }
      if (pque.empty()) {
        if (idx == N) {
          cout << "Yes\n";
          return;
        }
        auto [l, r, i] = LRI[idx];
        t = l;
      }else {
        t++;
      }
    }
  };

  ll T; cin >> T;
  REP(t, T) solve();
  return 0;
}

