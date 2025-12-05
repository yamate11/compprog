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
  // @InpMVec(N, ((U, dec=1), (D, dec=0), (L, dec=1), (R, dec=0))) [DdiWHgQW]
  auto U = vector(N, ll());
  auto D = vector(N, ll());
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 0; D[i] = v2;
    ll v3; cin >> v3; v3 -= 1; L[i] = v3;
    ll v4; cin >> v4; v4 -= 0; R[i] = v4;
  }
  // @End [DdiWHgQW]

  ll lim = 2000;
  vector brd(lim + 1, vector(lim + 1, 0LL));
  REP(i, 0, N) {
    brd[U[i]][L[i]]++;
    brd[U[i]][R[i]]--;
    brd[D[i]][L[i]]--;
    brd[D[i]][R[i]]++;
  }
  REP(i, 1, lim + 1) REP(j, 0, lim + 1) brd[i][j] += brd[i - 1][j];
  REP(i, 0, lim + 1) REP(j, 1, lim + 1) brd[i][j] += brd[i][j - 1];
  ll tot = 0;
  REP(i, 0, lim) REP(j, 0, lim) if (brd[i][j] >= 1) tot++;
  vector P(lim + 1, vector(lim + 1, 0LL));
  REP(i, 0, lim) REP(j, 0, lim) if (brd[i][j] == 1) P[i + 1][j + 1] = 1;
  REP(i, 1, lim + 1) REP(j, 1, lim + 1) P[i][j] += P[i - 1][j];
  REP(i, 1, lim + 1) REP(j, 1, lim + 1) P[i][j] += P[i][j - 1];
  REP(i, 0, N) {
    ll x = P[U[i]][L[i]] + P[D[i]][R[i]] - P[U[i]][R[i]] - P[D[i]][L[i]];
    cout << lim * lim - (tot - x) << "\n";
  }
  

  return 0;
}

