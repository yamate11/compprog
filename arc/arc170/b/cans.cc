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
  // @InpVec(N, A, dec=1) [ScEqQF0c]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [ScEqQF0c]

  vector pos(10, vector<ll>());
  REP(i, 0, N) pos[A[i]].push_back(i);

  // ll big = 1e18;
  vector<ll> B(N, N);
  REP(d, -4, 5) REP(a, 0, 10) {
    vector v(3, 0LL);
    v[0] = a;
    v[1] = a + d;
    v[2] = a + d + d;
    if (not (0 <= v[2] and v[2] < 10)) continue;
    for (ll p : pos[v[0]]) {
      auto it1 = upper_bound(ALL(pos[v[1]]), p);
      if (it1 == pos[v[1]].end()) break;
      ll q = *it1;
      auto it2 = upper_bound(ALL(pos[v[2]]), q);
      if (it2 == pos[v[2]].end()) break;
      ll r = *it2;
      updMin(B[p], r);
    }
  }
  vector C(N, 0LL);
  C[N - 1] = B[N - 1];
  REPrev(i, N - 2, 0) C[i] = min(C[i + 1], B[i]);
  ll ans = 0;
  REP(i, 0, N - 1) ans += N - C[i];
  cout << ans << endl;


  return 0;
}

