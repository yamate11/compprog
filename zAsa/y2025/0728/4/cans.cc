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

  ll N, M; cin >> N >> M;
  // @InpVec(N, X) [ozKORiFl]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [ozKORiFl]
  vector<ll> C(N + 1);
  REP(i, 0, M) {
    ll c, y; cin >> c >> y;
    C[c] = y;
  }
  vector tbl_init(N + 1, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 0, N + 1) {
      if (prev[j] >= 0) {
        if (j + 1 <= N) updMax(tbl[j + 1], prev[j] + X[i] + C[j + 1]);
        updMax(tbl[0], prev[j]);
      }
    }
  }
  ll ans = *max_element(ALL(tbl));
  cout << ans << endl;

  return 0;
}

