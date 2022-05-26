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

  ll N; cin >> N;
  unordered_set<string> seen;
  ll tmax = -1;
  ll ans = -1;
  REP(i, N) {
    string s; cin >> s;
    ll t; cin >> t;
    if (seen.find(s) != seen.end()) continue;
    seen.insert(s);
    if (tmax < t) {
      tmax = t;
      ans = i + 1;
    }
  }
  cout << ans << endl;

  return 0;
}

