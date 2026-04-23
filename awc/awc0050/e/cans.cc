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

  ll big = 1e18;
  ll N, M; cin >> N >> M;
  // @InpVec(N, C) [ErspLXnH]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [ErspLXnH]
  vector<ll> cov(N);
  REP(i, 0, N) {
    ll x = 0;
    REP(j, 0, M) {
      ll b; cin >> b;
      if (b) x |= (1LL << j);
    }
    cov[i] = x;
  }
  
  vector<ll> vec(1LL << M, big);
  REP(i, 0, N) updMin(vec[cov[i]], C[i]);
  REPrev(x, (1LL << M) - 1, 1) {
    REP(i, 0, M) if (x >> i & 1) {
      updMin(vec[x ^ (1LL << i)], vec[x]);
    }
  }
  REP(x, 1, 1LL << M) {
    ll y = x;
    while (true) {
      ll z = x ^ y;
      updMin(vec[x], vec[y] + vec[z]);
      if (y == 0) break;
      y = x & (y - 1);
    }
  }
  ll ans = vec[(1LL << M) - 1];
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

