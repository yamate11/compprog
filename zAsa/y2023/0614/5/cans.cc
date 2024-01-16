#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll T1, T2, A1, A2, B1, B2; cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  if (A1 < B1) {
    swap(A1, B1);
    swap(A2, B2);
  }
  A1 -= B1;
  A2 -= B2;
  ll x = T1 * A1;
  ll y = T2 * A2;
  if (x + y > 0) {
    cout << 0 << endl;
  }else if (x + y == 0) {
    cout << "infinity" << endl;
  }else {
    ll z = -(x + y);
    if (x % z == 0) {
      cout << 2 * (x / z) << endl;
    }else {
      cout << 2 * (x / z) + 1 << endl;
    }
  }

  return 0;
}

