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

  ll N, M; cin >> N >> M;
  // @InpVec(N, P) [LCI2zgRX]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [LCI2zgRX]
  // @InpNbrList(N, M, fwd, dec=1, dir=True) [SGSN3oSD]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [SGSN3oSD]
  vector<ll> tbl(N, -1LL);
  auto f = [&](auto rF, ll nd) -> ll {
    ll& r = tbl[nd];
    if (r < 0) {
      r = 0;
      for (ll peer : fwd[nd]) {
        if (P[nd] < P[peer]) {
          ll t = rF(rF, peer);
          r = max(r, t + 1);
        }
      }
    }
    return r;
  };
  ll ans = f(f, 0);
  cout << ans + 1 << endl;

  return 0;
}

