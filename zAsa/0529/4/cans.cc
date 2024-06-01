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

  ll N; cin >> N;
  // @InpVec(N, A) [3FsPWxIt]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [3FsPWxIt]

  ll ans = 1e18;
  REP(x, 0, 1LL << (N - 1)) {
    ll sum = 0;
    ll cur = A[0];
    REP(i, 1, N + 1) {
      if (i == N or x >> (i - 1) & 1) {
        sum ^= cur;
        if (i == N) break;
        cur = A[i];
      }else {
        cur |= A[i];
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;

  return 0;
}

