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
    // @InpVec(N, A) [hanXlqUv]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [hanXlqUv]
    
    vector<ll> ans(N);
    REP(i, 1, N - 1) ans[i] = (A[i - 1] + A[i + 1] - 2 * A[i]) / 2;
    ll t = 0;
    REP(i, 1, N - 1) t += i * ans[i];
    ans[N - 1] = (A[0] - t) / (N - 1);
    ll s = 0;
    REP(i, 1, N - 1) s += (N - 1 - i) * ans[i];
    ans[0] = (A[N - 1] - s) / (N - 1);
    REPOUT(i, 0, N, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

