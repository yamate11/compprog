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

  ll N, M, K, Q; cin >> N >> M >> K >> Q;
  // @InpVec(N, P) [St22aFe6]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [St22aFe6]
  // @InpNbrList(N, M, fwd, dir=True, dec=1) [blW85b0O]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [blW85b0O]

  vector<ll> tbl_init(N, -1LL);
  auto tbl = tbl_init;
  REP(i, 0, N) tbl[i] = (P[i] * 1) % Q;
  REP(i, 1, K) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 0, N) {
      if (prev[j] >= 0) {
        for (ll peer : fwd[j]) {
          updMax(tbl[peer], prev[j] + (P[peer] * (i + 1)) % Q);
        }
      }
    }
  }
  ll ans = 0;
  REP(i, 0, N) updMax(ans, tbl[i]);
  cout << ans << endl;

  return 0;
}

