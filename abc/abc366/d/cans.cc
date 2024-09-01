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
  vector A(N, vector(N, vector(N, 0LL)));
  REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) cin >> A[i][j][k];
  vector S(N + 1, vector(N + 1, vector(N + 1, 0LL)));
  REP(i, 0, N) REP(j, 0, N) REP(k, 0, N) S[i + 1][j + 1][k + 1] = A[i][j][k];
  REP(i, 1, N + 1) REP(j, 1, N + 1) REP(k, 1, N + 1) S[i][j][k] += S[i - 1][j][k];
  REP(i, 1, N + 1) REP(j, 1, N + 1) REP(k, 1, N + 1) S[i][j][k] += S[i][j - 1][k];
  REP(i, 1, N + 1) REP(j, 1, N + 1) REP(k, 1, N + 1) S[i][j][k] += S[i][j][k - 1];
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll Lx, Rx, Ly, Ry, Lz, Rz; cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz; Lx--; Ly--; Lz--;
    ll ans = S[Rx][Ry][Rz]
      - S[Lx][Ry][Rz] - S[Rx][Ly][Rz] - S[Rx][Ry][Lz] 
      + S[Rx][Ly][Lz] + S[Lx][Ry][Lz] + S[Lx][Ly][Rz]
      - S[Lx][Ly][Lz];
    cout << ans << "\n";
  }

  return 0;
}

