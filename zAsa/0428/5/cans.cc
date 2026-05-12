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

  ll N, A; cin >> N >> A;
  // @InpVec(N, X) [TueAkLkj]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [TueAkLkj]

  auto f = [&](ll K, ll S) -> ll {
    vector tbl(K + 1, vector(S + 1, 0LL));
    tbl[0][0] = 1;
    REP(i, 0, N) {
      REPrev(k, K - 1, 0) {
        REPrev(s, S, 0) {
          if (s + X[i] <= S) {
            tbl[k + 1][s + X[i]] += tbl[k][s];
          }
        }
      }
    }
    return tbl[K][S];
  };

  ll ans = 0;
  REP(i, 1, N + 1) ans += f(i, i * A);
  cout << ans << endl;
  return 0;
}

