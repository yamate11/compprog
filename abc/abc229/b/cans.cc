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

  string a, b; cin >> a >> b;
  reverse(ALL(a));
  reverse(ALL(b));
  REP(i, min(SIZE(a), SIZE(b))) {
    ll x = a[i] - '0';
    ll y = b[i] - '0';
    if (x + y >= 10) {
      cout << "Hard\n";
      return 0;
    }
  }
  cout << "Easy\n";

  return 0;
}

