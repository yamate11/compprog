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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpGrid(N, N, W) [0cG7GNvD]
  auto W = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; W[i][j] = v; }
  // @End [0cG7GNvD]
  vector<ll> d(1LL << N, 0LL);
  REP(x, 1, 1LL << N) {
    ll t = __builtin_ctzll(x);
    ll y = x & ~(1LL << t);
    ll r = 0;
    REP(s, t + 1, N) if (x >> s & 1) r += W[t][s];
    d[x] = d[y] + r;
  }
  vector<ll> tbl(1LL << N, -1LL);
  auto f = [&](auto rF, ll x) -> ll {
    ll& ret = tbl[x];
    if (ret < 0) {
      if (x == 0) ret = 0;
      else if (__builtin_popcountll(x) == 1) ret = K;
      else {
        ll v = K + d[x];
        ll y = (x - 1) & x;
        while (true) {
          if (y == 0) break;
          ll vv = K + d[y] + rF(rF, x & ~y);
          v = max(v, vv);
          y = (y - 1) & x;
        }
        ret = v;
      }
    }
    return ret;
  };
  ll ans = f(f, (1LL << N) - 1) - d[(1LL << N) - 1];
  cout << ans << endl;

  return 0;
}

