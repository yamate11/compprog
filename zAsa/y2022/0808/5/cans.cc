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

  ll N, Z, W; cin >> N >> Z >> W;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  if (N == 1) {
    cout << abs(A[0] - W) << endl;
    return 0;
  }
  cout << max(abs(A[N - 2] - A[N - 1]), abs(A[N - 1] - W)) << endl;

  return 0;
}

