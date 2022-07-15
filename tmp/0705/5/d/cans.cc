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

  ll N, M; cin >> N >> M;
  vector<ll> L(M), R(M), D(M);
  vector nbr(N, vector<pll>());
  REP(i, M) {
    ll l, r, d; cin >> l >> r >> d; l--; r--;
    nbr[l].emplace_back(r, d);
    nbr[r].emplace_back(l, -d);
  }

  ll big = 1e18;
  vector<ll> rec(N, big);
  bool fail = false;
  REP(i, N) {
    if (rec[i] != big) continue;
    auto dfs = [&](auto rF, ll nd) -> void {
      for (auto [c, d] : nbr[nd]) {
        if (rec[c] == big) {
          rec[c] = rec[nd] + d;
          rF(rF, c);
        }else if (rec[c] - rec[nd] != d) fail = true;
      }
    };
    rec[i] = 0;
    dfs(dfs, i);
  }
  cout << (fail ? "No" : "Yes") << endl;

  return 0;
}

