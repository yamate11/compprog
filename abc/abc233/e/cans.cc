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

  string X; cin >> X;
  ll sz = SIZE(X);
  vector<ll> s(sz + 1);
  REP(i, sz) s[i + 1] = s[i] + X[i] - '0';
  ll cst = 100;
  vector<ll> ans(cst + sz);
  REP(i, sz) {
    ll t = s[i + 1];
    ll j = cst + i;
    while (t > 0) {
      ll p = t + ans[j];
      ans[j] = p % 10;
      t = p / 10;
      j--;
    }
  }
  bool f = 0;
  REP(i, cst + sz) {
    if (!f && ans[i] == 0) continue;
    f = true;
    cout << ans[i];
  }
  cout << endl;
  
  return 0;
}

