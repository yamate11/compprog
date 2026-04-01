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

  ll N, C; cin >> N >> C;
  // @InpVec(N, W) [uhfYzblo]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [uhfYzblo]

  vector pre(1LL << N, 0LL);
  REP(x, 0, 1LL << N) {
    if (x == 0) pre[x] = 0;
    else {
      ll i = countr_zero((u64)x);
      pre[x] = pre[x ^ (1LL << i)] + W[i];
    }
  }

  vector tbl(1LL << N, -1LL);
  auto f = [&](auto rF, ll x) -> ll {
    ll& r = tbl[x];
    if (r < 0) {
      if (x == 0) r = 0; 
      else {
        ll y = x;
        r = N + 1;
        while (true) {
          ll s = pre[y];
          if (s <= C) updMin(r, 1 + rF(rF, x & ~y));
          y = (y - 1) & x;
          if (y == 0) break;
        }
      }
    }
    return r;
  };
  cout << f(f, (1LL << N) - 1) << endl;

  return 0;
}

