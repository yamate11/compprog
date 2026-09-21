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

  ll N, K, X; cin >> N >> K >> X;
  // @InpVec(N, A) [hs6zPo0O]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [hs6zPo0O]
  if (N == 1) {
    cout << (A[0] >= X ? 1 : 0) << "\n";
    return 0;
  }

  ll H1 = N / 2;
  ll H2 = N - H1;
  vector B(K + 1, vector<ll>{});
  REP(x, 0, 1LL << H1) {
    ll n = popcount((u64)x);
    if (n > K) continue;
    ll v = 0;
    REP(i, 0, H1) if (x >> i & 1) v += A[i];
    B[n].push_back(v);
  }
  REP(k, 0, K + 1) ranges::sort(B[k]);
  ll ans = 0;
  REP(y, 0, 1LL << H2) {
    ll n = popcount((u64)y);
    if (n > K) continue;
    ll w = 0;
    REP(i, 0, H2) if (y >> i & 1) w += A[H1 + i];
    ll m = K - n;
    ans += B[m].end() - ranges::lower_bound(B[m], X - w);
  }
  cout << ans << "\n";

  return 0;
}

