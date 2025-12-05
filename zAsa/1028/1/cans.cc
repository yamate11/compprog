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

  // @InpVec(10, S, type=string) [VHdbJovl]
  auto S = vector(10, string());
  for (int i = 0; i < 10; i++) { string v; cin >> v; S[i] = v; }
  // @End [VHdbJovl]

  ll A = 9, B = 0, C = 9, D = 0;
  REP(i, 0, 10) REP(j, 0, 10) {
    if (S[i][j] == '#') {
      updMin(A, i);
      updMax(B, i);
      updMin(C, j);
      updMax(D, j);
    }
  }
  cout << A + 1 << " " << B + 1 << "\n";
  cout << C + 1 << " " << D + 1 << "\n";

  return 0;
}

