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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, A) [qpaTbamD]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [qpaTbamD]

  ll ans = 0;
  auto enc = [&](ll i, ll j) -> ll { return i * W + j; };
  auto dec = [&](ll e) -> pll { return pll(e / W, e % W); };
  auto add = [&](ll x, ll i, ll j) -> ll {
    ll e = enc(i, j);
    return x | (1LL << e);
  };
  auto dfs = [&](auto rF, ll x, ll e) {
    auto covered1 = [&](ll ee) -> bool { return (x >> ee & 1); };
    auto covered2 = [&](ll ii, ll jj) -> bool { return covered1(enc(ii, jj)); };
    if (e == H * W) {
      ll s = 0;
      REP(i, 0, H) REP(j, 0, W) if (not covered2(i, j)) s ^= A[i][j];
      updMax(ans, s);
      return;
    }
    if (covered1(e)) return rF(rF, x, e + 1);
    auto [i, j] = dec(e);
    rF(rF, x, e + 1);
    if (j + 1 < W and not covered2(i, j) and not covered2(i, j + 1)) rF(rF, add(add(x, i, j), i, j + 1), e + 1);
    if (i + 1 < H and not covered2(i, j) and not covered2(i + 1, j)) rF(rF, add(add(x, i, j), i + 1, j), e + 1);
  };

  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0;
}

