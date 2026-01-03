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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpVec(N, A) [U6aOqE2y]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [U6aOqE2y]
    ranges::sort(A);
    vector<ll> B;
    ll s = 0;
    ll ans = 0;
    REP(i, 0, N) {
      s += A[i];
      B.push_back(A[i]);
      ll n = B.end() - ranges::lower_bound(B, s / (i + 1) + 1);
      ans = max(ans, n);
    }
    return ans;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

