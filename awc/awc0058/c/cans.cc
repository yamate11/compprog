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

  ll N, M, K; cin >> N >> M >> K;
  // @InpMVec(M, ((L, dec=1), (R, dec=0))) [hurVvWVr]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
  }
  // @End [hurVvWVr]

  vector<ll> D(N + 1, 0LL);
  REP(i, 0, M) {
    D[L[i]]++;
    D[R[i]]--;
  }
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    cur += D[i];
    if (cur >= K) ans++;
  }
  cout << ans << endl;

  return 0;
}

