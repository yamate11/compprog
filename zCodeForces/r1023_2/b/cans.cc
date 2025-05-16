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
    ll K; cin >> K;
    // @InpVec(N, A) [YT0tSu9B]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [YT0tSu9B]

    ll s = accumulate(ALL(A), 0LL);
    ll vmax = *max_element(ALL(A));
    ll vmin = *min_element(ALL(A));
    ll z = 0;
    REP(i, 0, N) if (A[i] == vmax) z++;
    if (vmax - 1 - vmin > K) return "Jerry";
    if (z >= 2 and vmax - vmin > K) return "Jerry";
    if (s % 2 == 0) return "Jerry";
    return "Tom";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

