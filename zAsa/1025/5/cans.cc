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

  ll N, X, Y; cin >> N >> X >> Y;
  // @InpMVec(N, (A, B)) [PVfFKNUX]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [PVfFKNUX]

  ll big = 1e18;
  vector tbl(X + 1, vector(N + 1, big));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    REPrev(x, X - 1, 0) REPrev(n, N - 1, 0) {
      if (tbl[x][n] < big) {
        ll newX = x + A[i];
        ll newY = tbl[x][n] + B[i];
        if (newX <= X and newY <= Y) updMin(tbl[newX][n + 1], newY);
      }
    }
  }
  REPrev(n, N, 0) REP(x, 0, X + 1) {
    if (tbl[x][n] < big) {
      cout << min(n + 1, N) << endl;
      return 0;
    }
  }

  return 0;
}

