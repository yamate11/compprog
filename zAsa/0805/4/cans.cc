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

  ll N; cin >> N;
  // @InpVec(N, T) [K4m1I3e4]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [K4m1I3e4]

  ll tot = accumulate(ALL(T), 0LL);
  ll lim = tot / 2 + 1;
  vector vec(lim + 1, false);
  vec[0] = true;
  REP(i, 0, N) {
    REPrev(x, lim, 0) {
      if (vec[x] and x + T[i] <= lim) {
        vec[x + T[i]] = true;
      }
    }
  }
  ll ans = tot;
  REPrev(x, lim, 0) {
    if (vec[x]) {
      ans = min(ans, max(tot - x, x));
    }
  }
  cout << ans << endl;
  return 0;
}

