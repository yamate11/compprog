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
  // @InpMVec(N, (R, T)) [gH2uo798]
  auto R = vector(N, ll());
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; R[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [gH2uo798]

  vector<ll> tbl(M + 1, -1LL);
  tbl[0] = 0;
  REP(i, 0, N) {
    REPrev(m, M, 0) {
      if (tbl[m] >= 0) {
        if (m + T[i] <= M) updMax(tbl[m + T[i]], tbl[m] + R[i]);
      }
    }
  }
  ll ans = *ranges::max_element(tbl);
  cout << ans << endl;

  return 0;
}

