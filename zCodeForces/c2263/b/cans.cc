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
    ll N, K; cin >> N >> K;
    if (K < N or 2 * N <= K) {
      cout << "-1\n";
      return;
    }
    vector ans(N, vector(N, -1LL));
    ll th = 2 * N - K - 1;
    REP(i, 0, th) ans[i][i] = i;
    REP(i, th, N) {
      ans[i][th] = i;
      if (i > th) ans[th][i] = N + (i - th - 1);
    }
    ll seq = K;
    REP(i, 0, N) REP(j, 0, N) {
      if (ans[i][j] < 0) ans[i][j] = seq++;
    }

    REP(i, 0, N) {
      REPOUT(j, 0, N, ans[i][j] + 1, " ");
    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

