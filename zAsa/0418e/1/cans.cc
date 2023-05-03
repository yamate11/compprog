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
  // @InpMVec(N, (X, Y, (U, type=char))) [TAVU2jdz]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto U = vector(N, char());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    char v3; cin >> v3; U[i] = v3;
  }
  // @End [TAVU2jdz]
  const ll big = 1e18;

  auto func1 = [&](auto& mp) -> ll {
    ll ret = big;
    for (auto& [_p, vec] : mp) {
      sort(ALL(vec));
      ll sz = SIZE(vec);
      REP(i, 0, sz - 1) {
        auto [x1, d1] = vec[i];
        auto [x2, d2] = vec[i + 1];
        if (d1 == 1 and d2 == -1) updMin(ret, 5 * (x2 - x1));
      }
    }
    return ret;
  };

  auto func2 = [&](auto& mp) -> ll {
    ll ret = big;
    for (auto& [_p, vec] : mp) {
      sort(ALL(vec));
      ll sz = SIZE(vec);
      REP(i, 0, sz - 1) {
        auto [x1, d1] = vec[i];
        auto [x2, d2] = vec[i + 1];
        if ((d1 == 1 and d2 == 0) or (d1 == 0 and d2 == -1)) updMin(ret, 10 * (x2 - x1));
      }
    }
    return ret;
  };


  ll ans = big;
  map<ll, vector<pll>> mp1, mp2, mp3, mp4, mp5, mp6;
  REP(i, 0, N) {
    if (U[i] == 'U') mp1[X[i]].emplace_back(Y[i], 1);
    else if (U[i] == 'D') mp1[X[i]].emplace_back(Y[i], -1);
  }
  updMin(ans, func1(mp1));
  REP(i, 0, N) {
    if (U[i] == 'R') mp2[Y[i]].emplace_back(X[i], 1);
    else if (U[i] == 'L') mp2[Y[i]].emplace_back(X[i], -1);
  }
  updMin(ans, func1(mp2));
  REP(i, 0, N) {
    if (U[i] == 'R') mp3[X[i] + Y[i]].emplace_back(X[i], 1);
    else if (U[i] == 'U') mp3[X[i] + Y[i]].emplace_back(X[i], 0);
  }
  updMin(ans, func2(mp3));
  REP(i, 0, N) {
    if (U[i] == 'D') mp4[X[i] + Y[i]].emplace_back(X[i], 0);
    else if (U[i] == 'L') mp4[X[i] + Y[i]].emplace_back(X[i], -1);
  }
  updMin(ans, func2(mp4));
  REP(i, 0, N) {
    if (U[i] == 'R') mp5[X[i] - Y[i]].emplace_back(X[i], 1);
    else if (U[i] == 'D') mp5[X[i] - Y[i]].emplace_back(X[i], 0);
  }
  updMin(ans, func2(mp5));
  REP(i, 0, N) {
    if (U[i] == 'U') mp6[X[i] - Y[i]].emplace_back(X[i], 0);
    else if (U[i] == 'L') mp6[X[i] - Y[i]].emplace_back(X[i], -1);
  }
  updMin(ans, func2(mp6));

  if (ans >= big) cout << "SAFE\n";
  else cout << ans << "\n";
  return 0;
}

