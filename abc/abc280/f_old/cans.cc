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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  vector nbr(N, vector<pll>());
  REP(i, 0, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    nbr[a].emplace_back(b, c);
    nbr[b].emplace_back(a, -c);
  }
  vector<bool> inconsis(N, false);
  vector<ll> pot(N, -1LL);
  vector<ll> root(N, -1LL);
  ll curRoot = -1;
  auto dfs = [&](auto rF, ll nd, ll ht) -> void {
    if (root[nd] >= 0) {
      assert(root[nd] == curRoot);
      if (pot[nd] != ht) inconsis[curRoot] = true;
      return;
    }
    root[nd] = curRoot;
    pot[nd] = ht;
    for (auto [cld, cost] : nbr[nd]) {
      rF(rF, cld, ht + cost);
    }
  };
  REP(i, 0, N) {
    if (root[i] < 0) {
      curRoot = i;
      dfs(dfs, i, 0);
    }
  }
  REP(_q, 0, Q) {
    ll x, y; cin >> x >> y; x--; y--;
    assert(root[x] >= 0 and root[y] >= 0);
    if (root[x] != root[y]) {
      cout << "nan\n";
    }else {
      if (inconsis[root[x]]) {
        cout << "inf\n";
      }else {
        cout << pot[y] - pot[x] << "\n";
      }
    }
  }


  return 0;
}

