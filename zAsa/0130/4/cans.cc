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

  ll N, K; cin >> N >> K;
  // @InpVec(K, A, dec=1) [NkJALvUK]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [NkJALvUK]

  if (K % 2 == 0) {
    ll ans = 0;
    REP(i, 0, K / 2) ans += A[2*i + 1] - A[2*i];
    cout << ans << endl;
    return 0;
  }

  ll sz = (K - 1) / 2;
  vector<ll> B(sz);
  vector<ll> C(sz);
  REP(i, 0, sz) {
    B[i] = A[2*i + 1] - A[2*i];
    C[i] = A[K - 1 - 2*i] - A[K - 2 - 2*i];
  }
  ll cur = 0;
  REP(i, 0, sz) cur += B[i];
  ll ans = cur;
  REP(i, 0, sz) {
    cur = cur + C[i] - B[sz - 1 - i];
    ans = min(ans, cur);
  }
  cout << ans << endl;
  
  return 0;
}

