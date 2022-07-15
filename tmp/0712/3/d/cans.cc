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

  ll N; cin >> N;
  vector<pll> LR;
  REP(i, N) {
    ll l, r; cin >> l >> r;
    LR.emplace_back(l, r);
  }
  sort(ALL(LR));
  ll l0 = -1, r0 = -1;
  vector<pll> ans;
  for (auto [l, r] : LR) {
    if (r0 < l) {
      if (l0 >= 0) ans.emplace_back(l0, r0);
      l0 = l;
      r0 = r;
    }else {
      r0 = max(r, r0);
    }
  }
  ans.emplace_back(l0, r0);
  for (auto [l, r] : ans) { cout << l << " " << r << "\n"; }

  return 0;
}

