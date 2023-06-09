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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [ZxKy78Cr]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [ZxKy78Cr]
  auto B = A;
  sort(ALL(B));
  vector vec(4, vector(4, 0LL));
  REP(i, 0, N) vec[A[i]][B[i]]++;
  ll ans = 0;
  REP(i, 0, 4) REP(j, i + 1, 4) {
    ll v = min(vec[i][j], vec[j][i]);
    ans += v;
    vec[i][j] -= v;
    vec[j][i] -= v;
  }
  vector<ll> p0, q0;
  REP(i, 1, 4) {
    if (vec[i][0] > 0) p0.push_back(i);
    if (vec[0][i] > 0) q0.push_back(i);
  }
  if (SIZE(p0) == 1) {
    ll k = p0[0];
    for (ll i : q0) {
      vec[k][i] += vec[0][i];
      ans += vec[0][i];
      vec[0][i] = 0;
    }
    vec[k][0] = 0;
  }else if (SIZE(q0) == 1) {
    ll k = q0[0];
    for (ll i : p0) {
      vec[i][k] += vec[i][0];
      ans += vec[i][0];
      vec[i][0] = 0;
    }
    vec[0][k] = 0;
  }
  REP(i, 0, 4) REP(j, i + 1, 4) {
    ll v = min(vec[i][j], vec[j][i]);
    ans += v;
    vec[i][j] -= v;
    vec[j][i] -= v;
  }
  if (vec[2][1] > 0) ans += 2 * vec[2][1];
  if (vec[1][2] > 0) ans += 2 * vec[1][2];
  cout << ans << endl;

  return 0;
}

