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

  ll N, K; cin >> N >> K;
  vector<ll> A(N), B(K);
  REP(i, N) cin >> A[i];
  REP(i, K) { cin >> B[i]; B[i]--; }
  ll vmax = 0;
  REP(i, N) vmax = max(vmax, A[i]);
  REP(i, K) if (A[B[i]] == vmax) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";

  return 0;
}

