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

using pll = pair<ll, ll>;
int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  vector r1(C, vector<pll>());
  REP(i, N) {
    ll s, t, c; cin >> s >> t >> c; c--;
    r1[c].emplace_back(s, t);
  }
  REP(c, C) sort(ALL(r1[c]));
  vector<pll> event;
  enum {START, TERM};
  REP(c, C) {
    ll sz = SIZE(r1[c]);
    ll idx = 0;
    while (idx < sz) {
      ll i;
      for (i = idx; i + 1 < sz and r1[c][i].second == r1[c][i + 1].first; i++);
      event.emplace_back(r1[c][idx].first, START);
      event.emplace_back(r1[c][i].second, TERM);
      idx = i + 1;
    }
  }
  sort(ALL(event));
  ll ans = 0;
  ll cur = 0;
  for (auto [t, e] : event) {
    if (e == START) cur++;
    else cur--;
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}

