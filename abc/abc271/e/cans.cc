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
  // @InpNbrList(N, M, fwd, dir=True, dec=1, read=(C), idx=idx)
  struct fwd_t {
    int nd;
    ll C;
    int idx;
    fwd_t() {}
    fwd_t(int nd_, ll C_) : nd(nd_), C(C_) {}
    fwd_t(int nd_, ll C_, int idx_) : nd(nd_), C(C_), idx(idx_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  vector<ll> startsAt(M), endsAt(M), costAt(M);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    startsAt[i] = u;
    endsAt[i] = v;
    ll C; cin >> C;
    costAt[i] = C;
    fwd[u].emplace_back(v, C, i);
  }
  // @InpVec(K, E, dec=1) [UtTSriix]
  auto E = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; E[i] = v; }
  // @End [UtTSriix]
  ll big = 1e18;
  vector<ll> tbl(N, big);
  tbl[0] = 0;
  REP(i, 0, K) {
    ll e = E[i];
    ll u = startsAt[e];
    ll v = endsAt[e];
    if (tbl[u] >= big) continue;
    updMin(tbl[v], tbl[u] + costAt[e]);
  }
  ll ans;
  if (tbl[N - 1] >= big) ans = -1;
  else ans = tbl[N - 1];
  cout << ans << endl;

  return 0;
}

