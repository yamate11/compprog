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

  ll a, b, c; cin >> a >> b >> c;
  if (2 * b <= a + c) {
    if ((a + c) % 2 == 0) {
      cout << (a + c) / 2 - b << endl;
    }else {
      cout << (a + c + 1) / 2 - b + 1 << endl;
    }
  }else {
    cout << b - (c - b) - a << endl;
  }

  return 0;
}

