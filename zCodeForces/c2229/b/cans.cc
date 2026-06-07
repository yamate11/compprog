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
    ll N; cin >> N;
    // @InpVec(N, A) [jieDuQ84]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [jieDuQ84]
    // @InpVec(N, B) [nBpja3nz]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [nBpja3nz]
    REP(i, 0, N) if (A[i] > B[i]) swap(A[i], B[i]);
    ll i0 = ranges::max_element(A) - A.begin();
    ll a0 = *ranges::max_element(A);
    ll t0 = accumulate(ALL(B), 0LL);
    ll base = a0 + t0;
    ll ans = base;
    REP(i, 0, N) {
      if (i == i0) ;
      else if (B[i] > a0) ans = max(ans, base + A[i] - A[i0]);
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

