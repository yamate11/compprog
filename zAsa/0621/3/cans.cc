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

  ll k, a, b; cin >> k >> a >> b;
  if (b <= a + 2) {
    cout << k + 1 << endl;
  }else if (a - 1 >= k) {
    cout << k + 1 << endl;
  }else {
    ll r = k - (a - 1);
    ll g = a + (b - a) * (r / 2);
    if (r % 2 == 1) g++;
    cout << g << endl;
  }

  return 0;
}

