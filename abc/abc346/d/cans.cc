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
  string S; cin >> S;
  // @InpVec(N, C) [SzxEVd6O]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [SzxEVd6O]

  ll big = 1e18;
  vector tbl_init(2, vector(2, big));
  auto tbl = tbl_init;
  if (S[0] == '0') {
    tbl[0][0] = 0;
    tbl[1][0] = C[0];
  }else {
    tbl[0][0] = C[0];
    tbl[1][0] = 0;
  }
  REP(i, 1, N) {
    auto prev = tbl;
    tbl = tbl_init;
    REP(d, 0, 2) {
      REP(c, 0, 2) {
        if (S[i] == '0') {
          updMin(tbl[0][1], prev[0][0]);
          // updMin(tbl[0][1], prev[0][1]);

          updMin(tbl[1][0], prev[0][0] + C[i]);
          updMin(tbl[1][1], prev[0][1] + C[i]);

          updMin(tbl[0][0], prev[1][0]);
          updMin(tbl[0][1], prev[1][1]);

          updMin(tbl[1][1], prev[1][0] + C[i]);
          // updMin(tbl[1][1], prev[1][1] + C[i]);
        }else {
          updMin(tbl[1][0], prev[0][0]);
          updMin(tbl[1][1], prev[0][1]);

          updMin(tbl[0][1], prev[0][0] + C[i]);
          // updMin(tbl[0][], prev[0][1] + C[i]);

          updMin(tbl[1][1], prev[1][0]);
          // updMin(tbl[][], prev[1][1]);

          updMin(tbl[0][0], prev[1][0] + C[i]);
          updMin(tbl[0][1], prev[1][1] + C[i]);
        }
      }
    }
  }
  cout << min(tbl[0][1], tbl[1][1]) << endl;


  return 0;
}

