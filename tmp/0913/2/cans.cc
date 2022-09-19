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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, W; cin >> N >> W;
  vector<bool> good(W + 1);
  // @InpVec(N, A) [Ub62oiuU]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Ub62oiuU]
  REP(i, 0, N) if (A[i] <= W) good[A[i]] = true;
  REP(i, 0, N) REP(j, i + 1, N) {
    ll s = A[i] + A[j];
    if (s <= W) good[s] = true;
  }
  REP(i, 0, N) REP(j, i + 1, N) REP(k, j + 1, N) {
    ll s = A[i] + A[j] + A[k];
    if (s <= W) good[s] = true;
  }
  ll ans = 0;
  REP(i, 1, W + 1) if (good[i]) ans++;
  cout << ans << endl;

  return 0;
}

