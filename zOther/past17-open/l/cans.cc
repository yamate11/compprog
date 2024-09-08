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
  auto big = 1e18;
  vector A(N, vector<ll>(N, big));
  vector B(N, vector<ll>(N, big));
  REP(i, 0, N) {
    A[i][i] = 0;
    REP(j, i + 1, N) {
      ll a; cin >> a;
      A[i][j] = A[j][i] = a;
    }
  }
  REP(i, 0, N) {
    B[i][i] = 0;
    REP(j, i + 1, N) {
      ll b; cin >> b;
      B[i][j] = B[j][i] = b;
    }
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) {
    updMin(A[i][j], A[i][k] + A[k][j]);
    updMin(B[i][j], A[i][k] + B[k][j]);
    updMin(B[i][j], B[i][k] + A[k][j]);
  }
  REP(i, 0, N) {
    REP(j, i + 1, N) cout << B[i][j] << " ";
    cout << "\n";
  }

  return 0;
}

