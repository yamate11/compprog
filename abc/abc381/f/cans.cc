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
  // @InpVec(N, A, dec=1) [v8GmOLp5]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [v8GmOLp5]
  ll sz = *ranges::max_element(A) + 1;

  vector pos(sz, vector<ll>());
  REP(i, 0, N) pos[A[i]].push_back(i);
  vector<ll> tbl(1LL << sz, N);
  ll ans2 = 0;
  tbl[0] = 0;
  REP(x, 1, 1LL << sz) {
    REP(i, 0, sz) {
      if (x >> i & 1) {
        ll y = x ^ (1LL << i);
        auto j = (ranges::lower_bound(pos[i], tbl[y]) - pos[i].begin()) + 1;
        if (j < ssize(pos[i])) {
          updMin(tbl[x], pos[i][j] + 1);
          updMax(ans2, (ll)popcount((u64)x));
        }
      }
    }
  }
  cout << 2 * ans2 << "\n";


  return 0;
}

