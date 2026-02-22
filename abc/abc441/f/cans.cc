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
  // @InpMVec(N, (P, V)) [FdhuklTN]
  auto P = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
  }
  // @End [FdhuklTN]

  vector tblL(N + 1, vector(M + 1, -1LL));
  tblL[0][0] = 0;
  REP(i, 0, N) {
    tblL[i + 1] = tblL[i];
    REPrev(j, M - P[i], 0) if (tblL[i][j] >= 0) updMax(tblL[i + 1][j + P[i]], tblL[i][j] + V[i]);
    REP(j, 1, M + 1) updMax(tblL[i + 1][j], tblL[i + 1][j - 1]);
  }
  vector tblR(N + 1, vector(M + 1, -1LL));
  tblR[N][0] = 0;
  REPrev(i, N - 1, 0) {
    tblR[i] = tblR[i + 1];
    REPrev(j, M - P[i], 0) if (tblR[i + 1][j] >= 0) updMax(tblR[i][j + P[i]], tblR[i + 1][j] + V[i]);
    REP(j, 1, M + 1) updMax(tblR[i][j], tblR[i][j - 1]);
  }
  string ans(N, ' ');
  REP(i, 0, N) {
    ll no = 0;
    REP(j, 0, M + 1) {
      ll k = M - j;
      no = max(no, tblL[i][j] + tblR[i + 1][k]);
    }
    ll yes = 0;
    REP(j, 0, M - P[i] + 1) {
      ll k = M - P[i] - j;
      yes = max(yes, tblL[i][j] + tblR[i + 1][k]);
    }
    yes += V[i];
    if (yes == no) ans[i] = 'B';
    if (yes < no) ans[i] = 'C';
    if (yes > no) ans[i] = 'A';
  }
  cout << ans << endl;
  return 0;
}

