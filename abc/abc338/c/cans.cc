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

  ll N; cin >> N;
  // @InpVec(N, Q) [B78gGJiv]
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; Q[i] = v; }
  // @End [B78gGJiv]
  // @InpVec(N, A) [NBTeu9QO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [NBTeu9QO]
  // @InpVec(N, B) [YmVipOXZ]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [YmVipOXZ]

  ll ans = 0;
  ll lim = 1e6;
  REP(i, 0, lim + 2) {
    ll s = lim;
    REP(j, 0, N) {
      ll r = Q[j] - A[j] * i;
      if (r < 0) {
        cout << ans << "\n";
        return 0;
      }
      if (B[j] == 0) continue;
      s = min(s, r / B[j]);
    }
    ans = max(ans, i + s);
  }
  assert(0);

  return 0;
}

