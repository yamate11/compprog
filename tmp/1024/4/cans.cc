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

  ll N; cin >> N;
  // @InpVec(N, T) [yt9Xi05u]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  ll sum = accumulate(ALL(T), 0LL);
  // @End [yt9Xi05u]
  ll  big = 1e18;
  vector tbl_init(sum + 1, false);
  auto tbl = tbl_init;
  tbl[0] = true;
  REP(i, 0, N) {
    auto prev = tbl;
    REP(t, 0, sum + 1) {
      if (prev[t]) tbl[t + T[i]] = true;
    }
  }
  ll ans = big;
  REP(t, 0, sum + 1) {
    if (tbl[t]) ans = min(ans, max(t, sum - t));
  }
  cout << ans << endl;

  return 0;
}

