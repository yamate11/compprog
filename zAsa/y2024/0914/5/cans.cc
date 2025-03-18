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
  // @InpMVec(N, (R, C, X)) [jn1Z56zL]
  auto R = vector(N, ll());
  auto C = vector(N, ll());
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; R[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
    ll v3; cin >> v3; X[i] = v3;
  }
  // @End [jn1Z56zL]
  map<pll, ll> mp0;
  REP(i, 0, N) mp0[pll(R[i], C[i])] = X[i];
  map<ll, ll> mpR, mpC;
  REP(i, 0, N) {
    mpR[R[i]] += X[i];
    mpC[C[i]] += X[i];
  }
  vector<pll> vecC;
  for (auto [c, t] : mpC) vecC.emplace_back(t, c);
  sort(ALL(vecC), greater<pll>());
  ll ans = 0;
  for (auto [r, s] : mpR) {
    for (auto [t, c] : vecC) {
      ll val = 0;
      auto it = mp0.find(pll(r, c));
      if (it == mp0.end()) val = s + t;
      else val = s + t - it->second;
      updMax(ans, val);
      if (it == mp0.end()) break;
    }
  }
  cout << ans << endl;

  return 0;
}

