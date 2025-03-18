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
  // @InpMVec(N, (T, X, A)) [hl5tj0Ue]
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
    ll v3; cin >> v3; A[i] = v3;
  }
  // @End [hl5tj0Ue]

  ll lim = 1e5;
  ll idx = 0;
  vector tbl_init(5, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(t, 1, lim + 1) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(x, 0, 5) {
      ll y = 0;
      if (idx < N and T[idx] == t and X[idx] == x) y = A[idx];
      REP(s, -1, 2) {
        if (0 <= x + s and x + s < 5 and prev[x + s] >= 0) updMax(tbl[x], prev[x + s] + y);
      }
    }
    if (idx < N and T[idx] == t) idx++;
  }
  cout << *max_element(ALL(tbl)) << endl;

  return 0;
}

