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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, W) [9HFLUY07]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [9HFLUY07]
  // @InpMVec(Q, ((L, dec=1), (R, dec=0), D)) [Z3QCUGuC]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  auto D = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
    ll v3; cin >> v3; D[i] = v3;
  }
  // @End [Z3QCUGuC]

  vector<ll> diff(N + 1);
  REP(i, 0, Q) {
    diff[L[i]] += D[i];
    diff[R[i]] -= D[i];
  }
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    cur += diff[i];
    if (W[i] <= cur) ans++;
  }
  cout << ans << endl;
  return 0;
}

