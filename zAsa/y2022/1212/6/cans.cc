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
  // @InpMVec(N, (X, Y)) [t1MZbxXX]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [t1MZbxXX]
  using sta = tuple<ll, ll, ll, ll>;
  vector<sta> rec;
  REP(i, 0, N) {
    rec.emplace_back(X[i] - 1, Y[i], 0, i);
    rec.emplace_back(X[i], Y[i] - 1, 1, i);
  }
  sort(ALL(rec),
       [&](sta p, sta q) -> bool {
         auto [xp, yp, tp, ip] = p;
         auto [xq, yq, tq, iq] = q;
         ll t = xp * yq - yp * xq;
         if (t != 0) return t > 0;
         return tp < tq;
       });
  vector<ll> fin(N);
  REP(j, 0, 2 * N) {
    auto [x, y, t, i] = rec[j];
    if (t == 0) fin[i] = j;
  }
  vector tbl(2*N, 0LL);
  ll cur = 0;
  REP(j, 0, 2*N) {
    cur = max(cur, tbl[j]);
    auto [x, y, t, i] = rec[j];
    if (t == 1) updMax(tbl[fin[i]], cur + 1);
  }
  cout << cur << endl;

  return 0;
}

