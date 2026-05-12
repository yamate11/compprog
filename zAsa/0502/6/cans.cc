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
  u64 K; cin >> K;
  // @InpMVec(N, ((A, type=u64), B)) [vIrIZ0jA]
  auto A = vector(N, u64());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    u64 v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [vIrIZ0jA]

  auto f = [&](u64 mask) -> ll {
    ll ret = 0;
    REP(i, 0, N) {
      if ((mask & A[i]) == 0) ret += B[i];
    }
    return ret;
  };

  u64 mask = ~K;
  ll ans = f(mask);
  REP(k, 0, 30) {
    if (K >> k & 1) {
      mask &= ~((1LL << k) - 1);
      mask |= (1LL << k);
      ans = max(ans, f(mask));
    }
  }
  cout << ans << endl;
  return 0;
}

