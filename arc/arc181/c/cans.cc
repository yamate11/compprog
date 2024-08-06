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
  // @InpVec(N, P, dec=1) [ZJGL8oJQ]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [ZJGL8oJQ]
  // @InpVec(N, Q, dec=1) [Q8cfv3oA]
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; Q[i] = v; }
  // @End [Q8cfv3oA]

  vector ans(N, string(N, ' '));
  REP(ii, 0, N) {
    ll i = P[ii];
    REP(jj, 0, N) {
      ll j = Q[jj];
      ans[i][j] = jj < N - ii ? '0' : '1';
    }
  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

