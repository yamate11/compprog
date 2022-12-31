#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define InpVec(vec, n) vector<ll> vec(n); REP(i, 0, (n)) cin >> vec[i]
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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

  ll N, M; cin >> N >> M;
  using sta = tuple<ll, ll, ll>;
  vector<sta> LRC;
  REP(i, 0, M) {
    ll l, r, c; cin >> l >> r >> c; l--;
    LRC.emplace_back(l, r, c);
  }
  sort(ALL(LRC));
  ll big = 1e18;
  vector<ll> tbl(N, big);
  tbl[0] = 0;
  for (auto [l, r, c] : LRC) {
    ll b = tbl[l];
    REP(i, l, r) updMin(tbl[i], b + c);
  }
  cout << (tbl[N - 1] >= big ? -1 : tbl[N - 1]) << endl;

  return 0;
}

