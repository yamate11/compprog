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
  // @InpVec(N, S, type=string) [1xyU8t1l]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [1xyU8t1l]
  ll big = 1LL << 60;
  vector mx(N, vector<ll>(N, 0LL));
  vector mn(N, vector<ll>(N, big));
  REP(i, 0, N) REP(j, 0, N) {
    if (i == 0 and j == 0) {
      mx[0][0] = mn[0][0] = 0;
    }else {
      ll here = S[i][j] == '@' ? 1 : 0;
      if (i > 0) {
        updMax(mx[i][j], mx[i - 1][j] + here);
        updMin(mn[i][j], mn[i - 1][j] + here);
      }
      if (j > 0) {
        updMax(mx[i][j], mx[i][j - 1] + here);
        updMin(mn[i][j], mn[i][j - 1] + here);
      }
    }
  }
  vector<ll> diff(2*N, 0LL);
  REP(i, 0, N) REP(j, 0, N) {
    diff[mn[i][j]]++;
    diff[mx[i][j] + 1]--;
  }
  vector<ll> ans(2 * N - 1);
  ll cur = 0;
  REP(i, 0, 2 * N - 1) {
    cur += diff[i];
    ans[i] = cur;
  }
  REPOUT(i, 0, 2 * N - 1, ans[i], "\n");

  return 0;
}

