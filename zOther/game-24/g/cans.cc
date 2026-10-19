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

  auto solve = [&]() -> string {
    ll N; cin >> N;
    // @InpMVec(N, (A, B)) [mkPq6MW5]
    auto A = vector(N, ll());
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; A[i] = v1;
      ll v2; cin >> v2; B[i] = v2;
    }
    // @End [mkPq6MW5]
    ll q0 = 1LL << 60;
    ll r0 = -1;
    REP(i, 0, N) {
      ll q = A[i] / (B[i] + 1);
      ll r = A[i] % (B[i] + 1);
      if (q < q0) {
        q0 = q;
        r0 = r;
      }else if (q == q0) {
        if (r < r0) r0 = r;
      }
    }
    if (r0 == 0) return "Bob";
    else return "Alice";

  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

