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

  ll N; cin >> N;
  // @InpMVec(N, (T, X, A)) [LfaD1bcB]
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
    ll v3; cin >> v3; A[i] = v3;
  }
  // @End [LfaD1bcB]
  ll big = 1e18;
  vector tbl_init(5, -big);
  auto tbl = tbl_init;
  tbl[0] = 0;
  ll idx = 0;
  REP(t, 1, T[N - 1] + 1) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll hole, size;
    if (T[idx] == t) {
      hole = X[idx];
      size = A[idx];
      idx++;
    }else {
      hole = -1;
      size = 0;
    }
    auto f = [&](ll a, ll b) -> void {
      ll add_size = b == hole ? size : 0;
      updMax(tbl[b], prev[a] + add_size);
    };
    REP(x, 0, 5) {
      if (x + 1 < 5) f(x, x + 1);
      f(x, x);
      if (x - 1 >= 0) f(x, x - 1);
    }
  }
  cout << *max_element(ALL(tbl)) << endl;


  return 0;
}

