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

  vector use{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  ll N, M; cin >> N >> M;
  // @InpVec(M, A) [KA8cY28r]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; A[i] = v; }
  // @End [KA8cY28r]
  ranges::sort(A);

  vector tbl(M + 1, vector(N + 1, -1LL));
  tbl[0][0] = 0;
  REP(i, 0, M) {
    ll u = use[A[i]];
    REP(j, 0, N + 1) {
      if (tbl[i][j] < 0) continue;
      REP(k, 0, N + 2) {
        ll j0 = j + u * k;
        if (j0 >= N + 1) break;
        updMax(tbl[i + 1][j0], tbl[i][j] + k);
      }
    }
  }
  assert(tbl[M][N] >= 0);
  string ans;
  ll g = N;
  REPrev(i, M - 1, 0) {
    ll u = use[A[i]];
    ll mx = g / u;
    REPrev(k, mx, 0) {
      if (tbl[i][g - u * k] + k == tbl[i + 1][g]) {
        ans += string(k, '0' + A[i]);
        g -= u * k;
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

