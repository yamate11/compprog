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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  /*
  if (N <= 2) {
    cout << "No\n";
    return 0;
  }
  */

  ll k, m;
  for (m = 1; true; m++) {
    k = m * (m - 1) / 2;
    if (k >= N) break;
  }
  if (k != N) {
    cout << "No\n";
    return 0;
  }
  vector<vector<ll>> ans(m);
  ll x = 0;
  REP(i, 0, m) REP(j, i + 1, m) {
    ans[i].push_back(x);
    ans[j].push_back(x);
    x++;
  }
  cout << "Yes\n";
  cout << m << "\n";
  REP(i, 0, m) {
    cout << SIZE(ans[i]) << " ";
    REPOUT(j, 0, SIZE(ans[i]), ans[i][j] + 1, " ");
  }
  

  return 0;
}

