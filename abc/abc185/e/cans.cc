#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(M);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < M; i++) cin >> B[i];
  vector<vector<ll>> tbl(N + 1, vector(M + 1, 0LL));
  tbl[0][0] = 0;
  for (ll i = 0; i <= N; i++) tbl[i][0] = i;
  for (ll j = 0; j <= M; j++) tbl[0][j] = j;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j <= M; j++) {
      ll cost = A[i-1] == B[j-1] ? 0 : 1;
      tbl[i][j] = min(tbl[i-1][j-1] + cost,
		      min(tbl[i-1][j] + 1, tbl[i][j-1] + 1));
    }
  }
#if DEBUG
  for (ll i = 0; i <= N; i++) {
    for (ll j = 0; j <= M; j++) {
      cerr << tbl[i][j] << " ";
    }
    cerr << endl;
  }
#endif
  cout << tbl[N][M] << endl;

  return 0;
}

