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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [Hm10gSdM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Hm10gSdM]
  vector<ll> SB(N + 1);
  vector<ll> SC(N + 1);
  REP(i, 0, N) {
    if (A[i] > 0) SB[i + 1] = SB[i] + A[i];
    else SB[i + 1] = SB[i];
    SC[i + 1] = SC[i] + A[i];
  }
  ll ans = 0;
  REP(i, 0, N - K + 1) {
    ll u = SC[i + K] - SC[i];
    ll v = SB[i] + SB[N] - SB[i + K];
    ll w = v + (u > 0 ? u : 0);
    ans = max(ans, w);
  }
  cout << ans << endl;
  

  return 0;
}

