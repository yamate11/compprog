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
  // @InpGrid(2, N, A) [auOsL1Vk]
  auto A = vector(2, vector(N, ll()));
  for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [auOsL1Vk]

  ll ans = 0;
  REP(p, 0, N) {
    ll t = 0;
    REP(i, 0, p + 1) t += A[0][i];
    REP(i, p, N) t += A[1][i];
    ans = max(ans, t);
  }
  cout << ans << "\n";
  return 0;
}

