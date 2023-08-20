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

  ll N; cin >> N;
  // @InpMVec(N, ((X, type=double), (Y, type=double))) [AZDzrKhR]
  auto X = vector(N, double());
  auto Y = vector(N, double());
  for (int i = 0; i < N; i++) {
    double v1; cin >> v1; X[i] = v1;
    double v2; cin >> v2; Y[i] = v2;
  }
  // @End [AZDzrKhR]

  auto dist = [&](ll i, ll j) -> double {
    ll x = X[i] - X[j];
    ll y = Y[i] - Y[j];
    return sqrt(x * x + y * y);
  };

  ll K = 32;
  double big = 1e18;
  vector tbl(N, vector(K, big));
  tbl[0][0] = 0.0;
  REP(i, 1, N) {
    REPrev(j, i - 1, 0) {
      REP(k, 0, K) {
        ll newK = k + (i - 1) - j;
        if (newK >= K) break;
        updMin(tbl[i][newK], tbl[j][k] + dist(j, i));
      }
    }
  }
  double ans = tbl[N - 1][0];
  REP(k, 1, K) {
    ll pen = 1LL << (k - 1);
    ans = min(ans, tbl[N - 1][k] + pen);
  }
  cout << ans << endl;
  return 0;
}

