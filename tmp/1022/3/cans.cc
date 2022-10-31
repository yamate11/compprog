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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll m; cin >> m;
  if (m < 100) {
    cout << "00\n";
  }else if (m <= 5000) {
    ll vv = m * 10 / 1000;
    if (vv < 10) cout << "0" << vv << endl;
    else cout << vv << endl;
  }else if (m <= 30*1000) {
    cout << (m/1000) + 50 << endl;
  }else if (m <= 70*1000) {
    cout << ((m/1000) - 30) / 5 + 80 << endl;
  }else {
    cout << "89\n";
  }

  return 0;
}

