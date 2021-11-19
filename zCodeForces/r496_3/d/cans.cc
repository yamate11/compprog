#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  string s; cin >> s;
  ll n = SIZE(s);
  vector tbl(n + 1, 0LL);
  tbl[0] = 0;
  REP(i, n) {
    ll x = tbl[i];
    ll acc = 0;
    REP2R(j, i, 0) {
      if (tbl[j] < tbl[i]) break;
      acc += s[j] - '0';
      if (acc % 3 == 0) {
        x = tbl[j] + 1;
        break;
      }
    }
    tbl[i + 1] = x;
  }
  cout << tbl[n] << endl;

  return 0;
}

