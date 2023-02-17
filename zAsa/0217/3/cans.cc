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

  ll N; cin >> N;
  vector<pll> vec;
  set<pll> ss;
  REP(i, 0, N) {
    ll x, y; cin >> x >> y;
    vec.emplace_back(x, y);
    ss.emplace(x, y);
  }
  ll ans = 0;
  REP(i, 0, N) REP(j, 0, N) {
    if (i == j) continue;
    auto [x1, y1] = vec[i];
    auto [x2, y2] = vec[j];
    if (x1 < x2 and y1 < y2) {
      if (ss.find({x1, y2}) != ss.end() and ss.find({x2, y1}) != ss.end()) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

