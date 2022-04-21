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

  ll N, M; cin >> N >> M;
  vector<ll> A(N + 1), B(M + 1), C(N + M + 1);
  REP(i, N + 1) cin >> A[i];
  REP(i, N + M + 1) cin >> C[i];

  REP2R(i, M, 0) {
    B[i] = C[N + i] / A[N];
    REP(j, N + 1) C[i + j] -= B[i] * A[j];
  }
  REP(i, M + 1) cout << B[i] << " ";
  cout << endl;

  return 0;
}

