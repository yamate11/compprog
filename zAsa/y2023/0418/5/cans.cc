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
  // @InpVec(N, S) [WnBiJdIM]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [WnBiJdIM]

  if (N == 1) {
    cout << "Yes\n0 0 " << S[0] << "\n";
    return 0;
  }
  if (N == 2) {
    cout << "Yes\n" << S[0] << " 0 0 " << S[1] << endl;
    return 0;
  }


  vector<ll> V(3);
  vector<ll> A(3);
  REP(i, 0, N - 1) {
    A[i % 3] += S[i + 1] - S[i];
    updMin(V[i % 3], A[i % 3]);
  }
  vector B(N + 2, 0LL);
  if (-V[0] - V[1] - V[2] <= S[0]) {
    cout << "Yes\n";
    B[0] = -V[0];
    B[1] = -V[1];
    B[2] = S[0] - B[0] - B[1];
    cout << B[0] << " " << B[1] << " " << B[2];
    REP(i, 3, N + 2) {
      B[i] = S[i - 2] - B[i - 2] - B[i - 1];
      cout << " " << B[i];
    }
    cout << endl;
  }else {
    cout << "No\n";
  }

  return 0;
}

