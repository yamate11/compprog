#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll M = 1LL << N;
  vector C(M, vector(N, 0LL));
  vector D(M, vector(N, 0LL));
  vector E(M, vector(N, 0LL));
  REP(i, M) REP(j, N) cin >> C[i][j];
  REP(j, N) {
    REP(m, 1LL << (N - 1 - j)) {
      ll base = m * (1LL << (j + 1));
      ll e = 0;
      REP(k, j) e += E[base + (1LL << (j - k))][j - 1 - k];
      D[base][j] = C[base][j] + e;
      REP2(i, 1, M) {
        if (i & 1) D[base + i][j] = D[base + i - 1][j] - C[base + i - 1][j] + C[base + i][j];
        else {
          ll z = __builtin_ctzll(i);
          ll lo = 
        }
      
        D[i][j] = ?;

      }
    }
  }

  return 0;
}

