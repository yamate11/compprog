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
  if (N < 2*K) {
    cout << -1 << endl;
    return 0;
  }
  ll c = N / (2 * K);
  REP(i, c - 1) {
    REP(j, K) cout << i * 2*K + K + j + 1 << " ";
    REP(j, K) cout << i * 2*K + j + 1 << " ";
  }
  ll t = (c - 1) * 2 * K;
  ll rem = N - t - 2*K;
  REP(j, K) cout << t + K + j + 1 << " ";
  if (rem < K) {
    REP(j, rem) cout << t + 2*K + j + 1 << " ";
    REP(j, K) cout << t + j + 1 << " ";
  }else {
    ll rem2 = rem - K;
    REP(j, rem2) cout << t + j + 1 << " ";
    REP(j, K) cout << t + 2*K + rem2 + j + 1 << " ";
    REP2(j, rem2, K) cout << t + j + 1 << " ";
    REP(j, rem2) cout << t + 2*K + j + 1 << " ";
  }
  cout << "\n";

  return 0;
}

