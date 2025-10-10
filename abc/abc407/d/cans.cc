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

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, A) [PoTzhiWR]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [PoTzhiWR]

  ll tot = 0;
  REP(i, 0, H) REP(j, 0, W) tot ^= A[i][j];
  ll ans = tot;

  set<ll> visited;

  auto f = [&](auto rF, ll score, ll x, ll i0, ll j0) {
    ans = max(ans, score);
    if (visited.contains(x)) return;
    visited.insert(x);

    auto enc = [&](ll i, ll j) -> ll {
      return i * W + j;
    };
    auto puttableH = [&](ll i, ll j) -> bool {
      ll e = enc(i, j);
      return j + 1 < W and not (x >> e & 1) and not (x >> (e + 1) & 1);
    };
    auto puttableV = [&](ll i, ll j) -> bool {
      ll e = enc(i, j);
      return i + 1 < H and not (x >> e & 1) and not (x >> (e + W) & 1);
    };
    auto puttable = [&](ll i, ll j) -> bool {
      return puttableH(i, j) or puttableV(i, j);
    };
    auto nxt = [&](ll i, ll j) -> pll {
      if (j + 1 < W) return {i, j + 1};
      if (i + 1 < H) return {i + 1, 0};
      return {-1, -1};
    };

    ll i = i0, j = j0;
    while (true) {
      ll e = enc(i, j);
      auto [i1, j1] = nxt(i, j);
      if (puttable(i, j)) {
        if (puttableH(i, j)) rF(rF, score ^ (A[i][j] ^ A[i][j + 1]), x | (1LL << e) | (1LL << (e + 1)), i1, j1);
        if (puttableV(i, j)) rF(rF, score ^ (A[i][j] ^ A[i + 1][j]), x | (1LL << e) | (1LL << (e + W)), i1, j1);
      }
      i = i1;
      j = j1;
      if (i < 0) break;
    }
  };
  f(f, tot, 0, 0, 0);
  cout << ans << endl;

  return 0;
}

