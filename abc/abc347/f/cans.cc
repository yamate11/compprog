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
  // @InpGrid(N, N, A) [u5OHz20j]
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [u5OHz20j]

  // ll big = 1e18;

  auto func = [&](const auto& X) -> ll {
    vector S(N + 1, vector(N + 1, 0LL));
    REP(i, 0, N) REP(j, 0, N) S[i + 1][j + 1] = X[i][j];
    REP(i, 1, N + 1) REP(j, 1, N + 1) S[i][j] += S[i][j - 1];
    REP(i, 1, N + 1) REP(j, 1, N + 1) S[i][j] += S[i - 1][j];
    vector T(N - M + 1, vector(N - M + 1, 0LL));
    REP(p, 0, N - M + 1) REP(q, 0, N - M + 1) T[p][q] = S[p][q] + S[p + M][q + M] - S[p + M][q] - S[p][q + M];
    
    vector MV(N + 1, vector(N + 1, -1LL));
    vector ML(N + 1, vector(N + 1, -1LL));
    vector MR(N + 1, vector(N + 1, -1LL));

    auto gv = [&](auto rF, ll p, ll q) -> ll {
      ll& ret = MV[p][q];
      if (ret < 0) {
        if (q - p < M) ret = 0;
        else if (q - p == M) ret = *max_element(ALL(T[p]));
        else ret = max(rF(rF, p, q - 1), rF(rF, p + 1, q));
      }
      return ret;
    };

    auto gl = [&](auto rF, ll p, ll q) -> ll {
      ll& ret = ML[p][q];
      if (ret < 0) {
        if (p > N - M or q < M) ret = 0;
        else ret = max(rF(rF, p + 1, q), max(rF(rF, p, q - 1), T[p][q - M]));
      }
      return ret;
    };

    auto gr = [&](auto rF, ll p, ll q) -> ll {
      ll& ret = MR[p][q];
      if (ret < 0) {
        if (p > N - M or q > N - M) ret = 0;
        else ret = max(rF(rF, p + 1, q), max(rF(rF, p, q + 1), T[p][q]));
      }
      return ret;
    };
    
    ll ret = 0;
    REP(p, 0, N) REP(q, p, N) updMax(ret, gv(gv, 0, p) + gv(gv, p, q) + gv(gv, q, N));
    REP(p, 0, N) REP(q, 0, N) updMax(ret, gv(gv, 0, p) + gl(gl, p, q) + gr(gr, p, q));
    return ret;

  };
  
  ll ans1 = func(A);
  vector B(N, vector(N, 0LL));
  REP(i, 0, N) REP(j, 0, N) B[i][j] = A[N - 1 - i][j];
  ll ans2 = func(B);
  REP(i, 0, N) REP(j, 0, N) B[i][j] = A[j][i];
  ll ans3 = func(B);
  REP(i, 0, N / 2) swap(B[i], B[N - 1 - i]);
  ll ans4 = func(B);
  ll ans = max(max(ans1, ans2), max(ans3, ans4));
  cout << ans << endl;


  return 0;
}

