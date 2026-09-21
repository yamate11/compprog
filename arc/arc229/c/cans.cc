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
    // @InpVec(N, A) [wXLhqTmN]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [wXLhqTmN]
    ranges::sort(A, greater<ll>());
    ll gain2 = A[0] + A[1];
    ll e = 0, o = 0;
    REP(i, 2, N) {
      if (A[i] % 2 == 0) e++;
      else o++;
    }
    if (A[0] % 2 == 0 and A[1] % 2 == 0) {
      if (o < e + 2) gain2 += 2 * o;
      else gain2 += 2 * (e + 1);
    }else if (A[0] % 2 != 0 and A[1] % 2 != 0) {
      if (e < o + 2) gain2 += 2 * e;
      else gain2 += 2 * (o + 1);
    }else {
      if (o <= e) gain2 += 2 * o + 1;
      else        gain2 += 2 * e + 1;
    }
    assert(gain2 % 2 == 0);
    ll tot = accumulate(ALL(A), 0LL);
    return tot - gain2 / 2;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

