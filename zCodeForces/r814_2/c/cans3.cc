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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;
    // @InpVec(N, A, dec=1) [YYhv8EDF]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [YYhv8EDF]
    vector<ll> B(N);
    B[0] = A[0];
    REP(i, 1, N)  B[i] = max(B[i - 1], A[i]);
    auto f = [&](ll i, ll k) -> ll {
      ll j = upper_bound(ALL(B), A[i]) - B.begin();
      if (j < i) return 0;
      if (j == N) return max(0LL, k - (i - 1));
      if (j - 1 <= k) return j - i;
      else if (k >= i - 1) return k - (i - 1);
      else return 0;
    };
    auto g = [&](ll k) -> ll {
      ll j = upper_bound(ALL(B), A[0]) - B.begin();
      if (j == N) return k;
      return min(k, j - 1);
    };
    REP(_q, 0, Q) {
      ll i, k; cin >> i >> k; i--;
      if (i > 0) cout << f(i, k) << "\n";
      else cout << g(k) << "\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

