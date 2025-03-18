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

  ll R, C, K; cin >> R >> C >> K;
  // @InpVec(R, S, type=string) [fOLHRPu1]
  auto S = vector(R, string());
  for (int i = 0; i < R; i++) { string v; cin >> v; S[i] = v; }
  // @End [fOLHRPu1]
  
  int valid = R % 2;
  vector B(R + C, vector(R + C, 0));
  REP(i, 0, R + C) REP(j, 0, R + C) if ((i + j) % 2 == valid) B[i][j] = 1;
  REP(i, 0, R) REP(j, 0, C) if (S[i][j] == 'o') B[i + j][-i + j + R] = 0;
  vector A(R + C + 1, vector(R + C + 1, 0));
  REP(i, 0, R + C) REP(j, 0, R + C) A[i + 1][j + 1] = B[i][j];
  REP(i, 1, R + C + 1) REP(j, 1, R + C + 1) A[i][j] += A[i][j - 1];
  REP(i, 1, R + C + 1) REP(j, 1, R + C + 1) A[i][j] += A[i - 1][j];
  ll sz = (K - 1) * 2 + 1;
  ll ans = 0;
  REP(i, 0, R + C + 1 - sz) REP(j, 0, R + C + 1 - sz) if ((i + j) % 2 == valid) {
    ll n = A[i][j] + A[i + sz][j + sz] - A[i + sz][j] - A[i][j + sz];
    if (n == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}

