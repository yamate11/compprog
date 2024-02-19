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

// @@ !! FUNC BEGIN f:updMaxMin
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
// @@ !! FUNC END f:updMaxMin

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [4k79072r]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [4k79072r]

  /*
  // @InpMVec(M, ((U, dec=1), (V, dec=1))) [suQ86BW4]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [suQ86BW4]
  */

  // @InpVec(N, W) [movScxGo]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [movScxGo]
  // @InpVec(N, A) [dNCAfSV0]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [dNCAfSV0]

  vector<ll> tbl(N, -1LL);
  auto func = [&](auto rF, ll nd) -> void {
    if (tbl[nd] >= 0) return;
    vector vec(W[nd], 0LL);
    for (ll peer : nbr[nd]) {
      if (W[peer] >= W[nd]) continue;
      rF(rF, peer);
      REPrev(w, W[nd] - 1, W[peer]) {
        updMax(vec[w], vec[w - W[peer]] + tbl[peer]);
      }
    }
    tbl[nd] = 1 + *max_element(ALL(vec));
  };
  REP(i, 0, N) func(func, i);
  ll ans = 0;
  REP(i, 0, N) ans += A[i] * tbl[i];
  cout << ans << endl;

  return 0;
}

