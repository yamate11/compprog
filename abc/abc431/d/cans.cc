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

  ll N; cin >> N;
  // @InpMVec(N, (W, H, B)) [USD7zyzu]
  auto W = vector(N, ll());
  auto H = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; H[i] = v2;
    ll v3; cin >> v3; B[i] = v3;
  }
  // @End [USD7zyzu]

  ll totW = accumulate(ALL(W), 0LL);
  ll maxHW = totW / 2;
  vector tbl_init(maxHW + 1, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 0, maxHW + 1) {
      if (prev[j] >= 0) {
        if (j + W[i] <= maxHW) updMax(tbl[j + W[i]], prev[j] + H[i]);
        updMax(tbl[j], prev[j] + B[i]);
      }
    }
  }
  ll ans = *ranges::max_element(tbl);
  cout << ans << endl;

  return 0;
}

