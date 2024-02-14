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

  ll H, W, N; cin >> H >> W >> N;
  // @InpMVec(N, ((R, dec=1), (C, dec=1), A)) [876sbtsg]
  auto R = vector(N, ll());
  auto C = vector(N, ll());
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; R[i] = v1;
    ll v2; cin >> v2; v2 -= 1; C[i] = v2;
    ll v3; cin >> v3; A[i] = v3;
  }
  // @End [876sbtsg]

  map<ll, vector<ll>> mp;
  REP(i, 0, N) mp[-A[i]].push_back(i);

  vector MR(N, 0LL);
  vector MC(N, 0LL);

  vector<ll> ans(N);
  for (const auto& [_num, vec] : mp) {
    map<ll, ll> updR;
    map<ll, ll> updC;
    for (ll i : vec) {
      ll z = max(MR[R[i]], MC[C[i]]) + 1;
      ans[i] = z;
      updMax(updR[R[i]], z);
      updMax(updC[C[i]], z);
    }
    for (auto [i, v] : updR) updMax(MR[i], v);
    for (auto [i, v] : updC) updMax(MC[i], v);
  }
  REPOUT(i, 0, N, ans[i] - 1, "\n");

  return 0;
}

