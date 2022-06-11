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
  double dn = N;
  double p1 = 6.0 * 1/dn * (N - K + 1) / dn * K / dn;
  double p2 = 3.0 * 1/dn * 1 / dn * K / dn;
  double p3 = 3.0 * 1/dn * 1 / dn * (N - K + 1) / dn;
  double p4 = 1/dn * 1/dn * 1/dn;
  double p = p1 - p2 - p3 + p4;
  cout << p << endl;

  return 0;
}

