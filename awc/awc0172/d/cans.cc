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

  ll N, Q; cin >> N >> Q;
  vector<ll> X(N + 1);
  X[0] = 0;
  REP(i, 0, N) {
    cin >> X[i + 1];
  }
  // @InpMVec(N, ((L, dec=0), (R, dec=0), A, B)) [VmrDkGpO]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 0; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
    ll v3; cin >> v3; A[i] = v3;
    ll v4; cin >> v4; B[i] = v4;
  }
  // @End [VmrDkGpO]
  // @InpVec(Q, C) [3tcNzFKy]
  auto C = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; C[i] = v; }
  // @End [3tcNzFKy]
  ll big = 1LL << 60;
  vector tbl(N + 1, vector(N + 1, big));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    REP(j, 0, N) {
      if (tbl[i][j] < big) {
        REP(k, L[i], R[i] + 1) {
          if (i + k <= N) {
            updMin(tbl[i + k][j + 1], tbl[i][j] + A[i] * (X[i + k] - X[i]) + B[i]);
          }
        }
      }
    }
  }
  if (*ranges::min_element(tbl[N]) == big) {
    REPOUT(i, 0, Q, -1, "\n");
  }else {
    REP(q, 0, Q) {
      ll val = big;
      REP(i, 0, N + 1) if (tbl[N][i] < big) {
        updMin(val, tbl[N][i] + i * C[q]);
      }
      cout << val << "\n";
    }
  }

  return 0;
}

