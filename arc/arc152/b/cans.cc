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

  ll N, L; cin >> N >> L;
  // @InpVec(N, A) [ry1hZk5x]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ry1hZk5x]
  ll s = 1e18;
  REP(i, 0, N) {
    ll q = L - A[i];
    ll k = lower_bound(ALL(A), q) - A.begin();
    if (k == N) {
      updMin(s, q - A[N - 1]);
    }else if (A[k] == q) {
      s = 0;
      break;
    }else if (k == 0) {
      updMin(s, A[0] - q);
    }else {
      updMin(s, min(A[k] - q, q - A[k - 1]));
    }
  }
  cout << 2 * L + 2 * s << endl;

  return 0;
}

