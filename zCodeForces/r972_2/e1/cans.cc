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

  auto solve = [&]() -> void {
    ll L, N, M; cin >> L >> N >> M;
    // @InpVec(L, A, dec=1) [3UhVv8qo]
    auto A = vector(L, ll());
    for (int i = 0; i < L; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [3UhVv8qo]
    // @InpGrid(N, M, B, dec=1) [MaPXaqWZ]
    auto B = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; v -= 1; B[i][j] = v; }
    // @End [MaPXaqWZ]

    ll kmax = 0;
    REP(i, 0, N) REP(j, 0, M) kmax = max(kmax, B[i][j]);

    vector arr(N, vector(kmax + 1, -10));
    REP(i, 0, N) REP(j, 0, M) updMax(arr[i][B[i][j]], j);

    vector<ll> border(N + 1, 0LL);
    REPrev(i, L - 1, 0) {
      auto prev_border = border;
      ll a = A[i];
      REPrev(n, N - 1, 0) {
        if (prev_border[n + 1] - 1 <= arr[n][a]) {
          border[n] = max(border[n + 1], arr[n][a] + 1);
        }else {
          border[n] = border[n + 1];
        }
      }
    }
    if (border[0] == 0) {
      cout << "N\n";
    }else {
      cout << "T\n";
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

