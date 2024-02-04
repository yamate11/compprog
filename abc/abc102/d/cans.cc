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

  ll big = 1e18;

  ll N; cin >> N;
  // @InpVec(N, A) [0lwsI6XJ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [0lwsI6XJ]
  vector S(N + 1, 0LL); REP(i, 0, N) S[i + 1] = S[i] + A[i];

  vector vL(N, 0LL), vR(N, 0LL);
  ll i = 1;
  REP(j, 2, N - 1) {
    ll cur = abs((S[i] - S[0]) - (S[j] - S[i]));
    while (true) {
      ll new_diff = abs((S[i + 1] - S[0]) - (S[j] - S[i + 1]));
      if (new_diff >= cur) break;
      cur = new_diff;
      i++;
    }
    vL[j] = i;
  }
  ll k = 3;
  REP(j, 2, N - 1) {
    ll cur = abs((S[k] - S[j]) - (S[N] - S[k]));
    while (true) {
      ll new_diff = abs((S[k + 1] - S[j]) - (S[N] - S[k + 1]));
      if (new_diff >= cur) break;
      cur = new_diff;
      k++;
    }
    vR[j] = k;
  }
  ll ans = big;
  REP(j, 2, N - 1) {
    vector v{S[vL[j]], S[j] - S[vL[j]], S[vR[j]] - S[j], S[N] - S[vR[j]]};
    updMin(ans, *max_element(ALL(v)) - *min_element(ALL(v)));
  }
  cout << ans << endl;
  return 0;
}

