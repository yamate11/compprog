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

  ll N, M, L; cin >> N >> M >> L;
  // @InpVec(N, A) [kNYA4IAJ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kNYA4IAJ]
  // @InpVec(M, B) [gMOULT9C]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [gMOULT9C]

  // @InpMVec(L, ((C, dec=1), (D, dec=1))) [sGkMx7IA]
  auto C = vector(L, ll());
  auto D = vector(L, ll());
  for (int i = 0; i < L; i++) {
    ll v1; cin >> v1; v1 -= 1; C[i] = v1;
    ll v2; cin >> v2; v2 -= 1; D[i] = v2;
  }
  // @End [sGkMx7IA]

  vector info(N, set<ll>());
  REP(i, 0, L) info[C[i]].insert(D[i]);

  vector ord(M, 0LL);
  REP(i, 0, M) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool { return B[i] > B[j]; });

  ll ans = 0;
  REP(i, 0, N) {
    REP(jj, 0, M) {
      ll j = ord[jj];
      if (not info[i].contains(j)) {
        updMax(ans, A[i] + B[j]);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

