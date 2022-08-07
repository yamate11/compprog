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

  ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
  ll l0 = max(l1, l2);
  ll r0 = min(r1, r2);
  if (r0 < l0) {
    cout << 0 << endl;
  }else {
    cout << r0 - l0 << endl;
  }

  return 0;
}

