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

  ll n, m; cin >> n >> m;
  ll x = m - 2 * n;
  REP(b, x + 1) {
    if ((x - b) % 2 != 0) continue;
    ll c = (x - b) / 2;
    ll a = n - (b + c);
    if (a < 0) continue;
    if (2 * a + 3 * b + 4 * c != m) continue;
    cout << a << " " << b << " " << c << endl;
    return 0;
  }
  cout << "-1 -1 -1\n";

  return 0;
}

