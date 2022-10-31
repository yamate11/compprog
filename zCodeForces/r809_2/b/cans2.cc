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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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
    // @InpVec(N, C, dec=1) [oLMMkmpB]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
    // @End [oLMMkmpB]
    vector<ll> recE(N, -1), recO(N, -1);
    vector<ll> prevE(N), prevO(N);
    REP(i, 0, N) {
      prevE[i] = recE[C[i]];
      prevO[i] = recO[C[i]];
      if (i % 2 == 0) recE[C[i]] = i;
      else            recO[C[i]] = i;
    }
    vector<ll> self(N);
    vector<ll> cum(N);
    REP(i, 0, N) {
      auto getA = [&]() -> ll {
        if (i % 2 == 0) {
          ll p = prevO[i];
          if (p < 0) return -1;
          else return p;
          /*
          else if (p <= i - 3) return p;
          else return prevO[p];
          */
        }else {
          ll p = prevE[i];
          if (p < 0) return -1;
          else return p;
          /*
          else if (p <= i - 3) return p;
          else return prevE[p];
          */
        }
      };
      auto getB = [&]() -> ll {
        if (i % 2 == 0) return prevE[i];
        else return prevO[i];
      };
      ll p = getA();
      if (p >= 0) {
        self[i] = cum[p] + 1;
      }else {
        self[i] = 1;
      }
      ll q = getB();
      if (q >= 0) cum[i] = max(self[i], cum[q]);
      else        cum[i] = self[i];
    }
    vector<ll> ans(N);
    REP(i, 0, N) {
      updMax(ans[C[i]], self[i]);
    }
    REPOUT(i, 0, N, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

