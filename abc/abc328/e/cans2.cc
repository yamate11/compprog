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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [3fkMgw6u]
  struct nbr_t {
    int nd;
    ll W;
    nbr_t() {}
    nbr_t(int nd_, ll W_) : nd(nd_), W(W_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [3fkMgw6u]

  auto weight = vector(N, vector(N, -1LL));
  REP(i, 0, N) {
    for (auto [peer, w] : nbr[i]) {
      weight[i][peer] = w;
      weight[peer][i] = w;
    }
  }
  
  ll ans = K;
  vector used(N, false);
  vector done(N, false);
  auto dfs = [&](auto rF, ll nd, ll ontree, ll tw) -> void {
    done[nd] = true;
    vector<ll> curnbr;
    for (auto [peer, w] : nbr[nd]) {
      if (not used[peer]) curnbr.push_back(peer);
    }
    ll num = SIZE(curnbr);
    REP(x, 0, 1LL << num) {
      ll thistw = 0;
      REP(j, 0, num) {
        if (x >> j & 1) {
          ll peer = curnbr[j];
          used[peer] = true;
          thistw += weight[nd][peer];
        }
      }
      ll ont = __builtin_popcountll(x);
      if (ontree + ont == N) {
        updMin(ans, (tw + thistw) % K);
      }else {
        REP(i, 0, N) {
          if (used[i] and not done[i]) {
            rF(rF, i, ontree + ont, tw + thistw);
          }
        }
      }
      REP(j, 0, num) {
        if (x >> j & 1) {
          ll peer = curnbr[j];
          used[peer] = false;
        }
      }
    }
    done[nd] = false;
  };

  used[0] = true;
  dfs(dfs, 0, 1, 0);
  cout << ans << endl;

  return 0;
}

