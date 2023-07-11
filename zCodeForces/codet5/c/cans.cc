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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [TiXv4SAC]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [TiXv4SAC]
    vector pos(N + 1, vector<ll>());
    vector pidx(N + 1, 0LL);
    REP(i, 0, N) {
      pidx[i] = SIZE(pos[A[i]]);
      pos[A[i]].push_back(i);
    }

    vector<ll> tbl(N + 1, 0LL);
    vector<bool> use(N, false);
    REPrev(k, N - 1, 0) {
      const auto& vec = pos[A[k]];
      ll v = tbl[k + 1];
      ll idx = pidx[k];
      if (idx + 1 < SIZE(vec)) {
        ll inxt = vec[idx + 1];
        if (use[inxt]) {
          ll w = tbl[inxt] + inxt - k;
          if (w > v) {
            v = w;
            use[k] = true;
          }
        }else {
          ll w = tbl[inxt + 1] + inxt - k + 1;
          if (w > v) {
            v = w;
            use[k] = true;
          }
        }
      }
      tbl[k] = v;
    }
    cout << tbl[0] << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

