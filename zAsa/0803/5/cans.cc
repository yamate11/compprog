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

  ll N, T; cin >> N >> T;
  // @InpMVec(N, (A, B)) [uoiSJTHz]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [uoiSJTHz]

  vector<ll> ord(N);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool { return A[i] < A[j]; });

  vector tbl_init(T + 1, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    auto prev = tbl;
    REP(t, 0, T) {
      if (prev[t] < 0) continue;
      ll newt = min(T, t + A[i]);
      updMax(tbl[newt], prev[t] + B[i]);
    }
  }
  cout << *max_element(ALL(tbl)) << endl;

  return 0;
}

