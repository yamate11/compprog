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

int main() {
  ll R, C, K; cin >> R >> C >> K;
  vector<string> S(R); REP(i, 0, R) cin >> S[i];
  
  vector B(R + C, vector(R + C, 0));
  REP(i, 0, R) REP(j, 0, C) if (S[i][j] == 'x') B[i + j][-i + j + R] = 1;
  vector A(R + C + 1, vector(R + C + 1, 0));
  REP(i, 0, R + C)     REP(j, 0, R + C)     A[i + 1][j + 1] = B[i][j];
  REP(i, 1, R + C + 1) REP(j, 1, R + C + 1) A[i][j]         += A[i][j - 1];
  REP(i, 1, R + C + 1) REP(j, 1, R + C + 1) A[i][j]         += A[i - 1][j];
  ll sz = (K - 1) * 2 + 1;
  ll ans = 0;
  REP(i, 0, R) REP(j, 0, C) {
    ll x = i + j, y = -i + j;
    if (x + sz < R + C + 1 and y + sz < R + C + 1 and \
        (A[x][y] + A[x + sz][y + sz] - A[x + sz][y] - A[x][y + sz] == 0)) ans++;
  }
  cout << ans << endl;
  return 0;
}

