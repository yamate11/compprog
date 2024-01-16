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

  ll N, P; cin >> N >> P;
  // @InpMVec(N, (A, B)) [VuGMOwfw]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [VuGMOwfw]
  vector<pll> AB;
  REP(i, 0, N) AB.emplace_back(A[i], B[i]);
  sort(ALL(AB), greater<pll>());
  vector<ll> C(N + 1);
  C[N] = 0;
  REPrev(i, N - 1, 0) C[i] = max(AB[i].second, C[i + 1]);
  auto tbl = vector(P + 1, -1LL);
  tbl[0] = 0;
  ll ans = C[0];
  REP(i, 0, N) {
    REPrev(p, P, 0) {
      if (tbl[p] < 0) continue;
      ll sat = AB[i].second;
      ll q = p + AB[i].first;
      if (q <= P) {
        updMax(tbl[q], tbl[p] + sat);
        updMax(ans, tbl[q] + C[i + 1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

