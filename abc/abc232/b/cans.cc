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

  string s, t; cin >> s >> t;
  ll d = t[0] - s[0];
  if (d < 0) d += 26;
  ll n = SIZE(s);
  REP(i, n) {
    ll e = t[i] - s[i];
    if (e < 0) e += 26;
    if (d != e) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

