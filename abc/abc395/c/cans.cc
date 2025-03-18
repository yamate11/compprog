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
  // @InpVec(N, A) [ZkeHEh3Z]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ZkeHEh3Z]

  ll vmax = *max_element(ALL(A));
  vector vec(vmax + 1, vector<ll>());
  REP(i, 0, N) {
    vec[A[i]].push_back(i);
  }
  ll big = 1e18;
  ll ans = big;
  REP(a, 0, vmax + 1) {
    REP(i, 0, ssize(vec[a]) - 1) ans = min(ans, vec[a][i + 1] - vec[a][i] + 1);
  }
  if (ans == big) ans = -1;
  cout << ans << endl;
  return 0;
}

