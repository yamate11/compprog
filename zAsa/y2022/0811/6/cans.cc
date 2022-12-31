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
  vector<ll> ans(N, -1000);
  if (2*K > N) {
    cout << -1 << endl;
    return 0;
  }
  ll base = 0;
  for ( ; base + 4 * K <= N; base += 2 * K) {
    REP(j, K) {
      ans[base + j] = base + K + j;
      ans[base + K + j] = base + j;
    }
  }
  ll sz = N - base;
  if (sz <= 3*K) {
    REP(i, sz - K) ans[base + i] = base + i + K;
    REP(i, K) ans[base + sz - K + i] = base + i;
  }else {
    REP(i, K) ans[base + i] = base + i + K;
    REP2(i, sz - K, sz) ans[base + i - K] = base + i;
    REP(i, sz - 3*K) {
      ans[base + K + i] = base + i;
      ans[base + 3 * K + i] = base + 2 * K + i;
    }
    REP2(i, sz - 3*K, K) ans[base + 2*K + i] = base + i;
  }
  for(ll a : ans) cout << a + 1 << " ";
  cout << endl;
  

  return 0;
}

