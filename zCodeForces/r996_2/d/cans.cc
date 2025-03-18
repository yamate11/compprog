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

  auto solve = [&]() -> void {
    ll N, K, L; cin >> N >> K >> L;
    // @InpVec(N, A) [XoWwI7Ko]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [XoWwI7Ko]
    K *= 2;
    L *= 2;
    REP(i, 0, N) A[i] *= 2;
    ll t = A[0];
    ll q = K;
    REP(i, 1, N) {
      if (A[i] < q) {
        ll p = min(A[i] + t, q);
        q = p + K;
      }else {
        ll p = max(A[i] - t, q);
        assert((p - q) % 2 == 0);
        t = t + (p - q) / 2;
        q = (p + q) / 2 + K;
      }
      if (q >= L) {
        cout << t << "\n";
        return;
      }
    }
    cout << t + (L - q) << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

