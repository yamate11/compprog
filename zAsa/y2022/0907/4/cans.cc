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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X; cin >> X;
  vector<vector<ll>> cands;
  REP(k, 1, 19) REP(a, 1, 10) REP(d, -9, 9) {
    bool succ = true;
    vector<ll> v(k);
    REP(i, 0, k) {
      if (i == 0) v[i] = a;
      else v[i] = v[i - 1] + d;
      if (not (v[i] >= 0 and v[i] <= 9)) succ = false;
    }
    if (succ) cands.push_back(move(v));
  }
  auto toNum = [&](auto& v) -> ll {
    ll ret = 0;
    REP(i, 0, SIZE(v)) ret = ret * 10 + v[i];
    return ret;
  };
  ll ans = 2e18;
  for (auto& v : cands) {
    ll t = toNum(v);
    if (X <= t and t < ans) ans = t;
  }
  cout << ans << endl;

  return 0;
}

