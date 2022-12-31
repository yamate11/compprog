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

  ll M, K; cin >> M >> K;
  if (M == 0) {
    if (K == 0) cout << "0 0\n";
    else cout << "-1\n";
    return 0;
  }
  if (M == 1) {
    if (K == 0) cout << "0 0 1 1\n";
    else cout << "-1\n";
    return 0;
  }
  if ((1LL << M) <= K) {
    cout << "-1\n";
    return 0;
  }
  REP(i, (1LL << M)) if (i != K) cout << i << " ";
  cout << K << " ";
  REP2R(i, (1LL << M) - 1, 0) if (i != K) cout << i << " ";
  cout << K << endl;
  

  return 0;
}

