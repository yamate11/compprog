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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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
    ll N, X, Y; cin >> N >> X >> Y;
    // @InpVec(N, A, (char, int), dec='0') [4rNCYLrO]
    auto A = vector(N, int());
    for (int i = 0; i < N; i++) { char v; cin >> v; v -= '0'; A[i] = v; }
    // @End [4rNCYLrO]
    // @InpVec(N, B, (char, int), dec='0') [I0aIySh2]
    auto B = vector(N, int());
    for (int i = 0; i < N; i++) { char v; cin >> v; v -= '0'; B[i] = v; }
    // @End [I0aIySh2]

    ll cnt = 0;
    REP(i, 0, N) if (A[i] != B[i]) cnt++;
    if (cnt % 2 != 0) {
      cout << -1 << "\n";
      return;
    }

    if (Y <= X) {

      if (cnt >= 4) {
        cout << Y * (cnt / 2) << "\n";
      }else if (cnt == 0) {
        cout << 0 << "\n";
      }else if (cnt == 2) {
        ll b = false;
        REP(i, 0, N) {
          if (A[i] != B[i]) {
            if (A[i + 1] != B[i + 1]) { b = true; break; }
            else { b = false; break; }
          }
        }
        if (b) {
          cout << min(X, 2 * Y) << "\n";
        }else {
          cout << Y << "\n";
        }
      }

    }else {

      ll big = 1e18;
      vector tbl(2, vector(2, vector(N + 1, big)));
      tbl[0][0][0] = 0;
      REP(i, 0, N) {
        if (A[i] == B[i]) {
          updMin(tbl[0][0][i + 1], tbl[0][0][i]);
          updMin(tbl[1][1][i + 1], tbl[0][0][i] + X);
          updMin(tbl[1][0][i + 1], tbl[0][1][i]);
          updMin(tbl[0][1][i + 1], tbl[0][1][i] + X);
          updMin(tbl[1][0][i + 1], tbl[1][0][i]);
          updMin(tbl[1][1][i + 1], tbl[1][1][i] + X);
        }else {
          updMin(tbl[0][1][i + 1], tbl[0][0][i]);
          updMin(tbl[1][0][i + 1], tbl[0][0][i] + X);
          updMin(tbl[1][1][i + 1], tbl[0][1][i]);
          updMin(tbl[0][0][i + 1], tbl[0][1][i] + X);
          updMin(tbl[1][1][i + 1], tbl[1][0][i]);
          updMin(tbl[0][0][i + 1], tbl[1][0][i] + Y);
          updMin(tbl[1][0][i + 1], tbl[1][1][i] + X);
          updMin(tbl[1][0][i + 1], tbl[1][1][i] + Y);
        }
      }
      cout << tbl[0][0][N] << "\n";

    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

