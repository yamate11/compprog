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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll P = 0;
  REP(i, 4) REP(j, 4) {
    ll v; cin >> v;
    ll z = i * 4 + j;
    if (v) P |= (1LL << z);
  }
  vector<vector<ll>> nbr(16);
  REP(i, 4) REP(j, 4) {
    ll z = i * 4 + j;
    auto add = [&](ll p, ll q) -> void {
      if (p < 0 or p >= 4 or q < 0 or q >= 4) return;
      nbr[z].push_back(p * 4 + q);
    };
    add(i - 1, j); add(i + 1, j); add(i, j - 1); add(i, j + 1);
  }
  const vector<ll> outmost = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};
  auto conn = [&](ll x) -> bool {
    ll t = 0;
    for (; t < 16; t++) if (x >> t & 1) break;
    if (t == 16) return true;
    ll rec = 0;
    auto dfs = [&](auto rF, ll i) -> void {
      if (rec >> i & 1) return;
      rec |= (1LL << i);
      for (ll j : nbr[i]) if (x >> j & 1) rF(rF, j);
    };
    dfs(dfs, t);
    return (x & rec) == x;
  };
  auto outreach = [&](ll x) -> bool {
    ll rec = 0;
    auto dfs = [&](auto rF, ll i) -> void {
      if (rec >> i & 1) return;
      rec |= (1LL << i);
      for (ll j : nbr[i]) if (not (x >> j & 1)) rF(rF, j);
    };
    for (ll i : outmost) if (not (x >> i & 1)) dfs(dfs, i);
    return (x | rec) == ((1LL << 16) - 1);
  };
  ll ans = 0;
  REP(x, 1LL << 16) if (((P & x) == P) and conn(x) and outreach(x)) ans++;
  cout << ans << endl;

  return 0;
}

