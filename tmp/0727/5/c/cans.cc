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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    vector<ll> A(N + 1); REP(i, N + 1) cin >> A[i];
    if (N == 0) return A[0] == 1 ? 1 : -1;
    if (A[0] > 0) return -1;
    vector<ll> C(N + 1, 0LL);
    REP2R(i, N - 1, 0) C[i] = A[i + 1] + C[i + 1];
    vector<ll> B(N + 1, 0LL);
    B[0] = 1;
    REP2(i, 1, N + 1) {
      B[i] = min(2 * B[i - 1] - A[i], C[i]);
      if (B[i] < 0) return -1;
    }
    ll ans = 0;
    REP(i, N + 1) ans += A[i] + B[i];
    return ans;
  };

  cout << solve() << endl;
  return 0;
}

