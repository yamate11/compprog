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

  ll N, M; cin >> N >> M;
  vector B(N, vector(M, 0LL));
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, M) B[i][j] = s[j] - '0';
  }


  vector A(N, vector(M, 0LL));

  REP(i, 1, N - 1) REP(j, 1, M - 1) {
    A[i][j] = B[i - 1][j];
    B[i - 1][j] -= A[i][j];
    B[i + 1][j] -= A[i][j];
    B[i][j - 1] -= A[i][j];
    B[i][j + 1] -= A[i][j];
  }
  REP(i, 0, N) {
    REPOUT(j, 0, M, A[i][j], "");
  }

  return 0;
}

