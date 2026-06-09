#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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
  vector tbl(N, vector(10, pll(-1, -1)));
  queue<pll> modified;
  modified.emplace(0, 0);
  auto sch = [&]() -> ll {
    while (not modified.empty()) {
      auto [r0, d0] = modified.front(); modified.pop();
      REP(d, max(1LL, d0), 10) {
        ll r = (10 * r0 + d) % N;
        if (tbl[r][d].first < 0) {
          tbl[r][d] = {r0, d0};
          if (r == 0) return d;
          REP(dd, d + 1, 10) {
            if (tbl[r][dd].first >= 0) break;
            tbl[r][dd] = {r0, d0};
          }
          modified.emplace(r, d);
        }
      }
    }
    return -1;
  };
  ll d = sch();
  if (d < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> ans{d};
  ll r = 0;
  while (true) {
    tie(r, d) = tbl[r][d];
    if (r == 0 and d == 0) break;
    ans.push_back(d);
  }
  ranges::reverse(ans);
  REPOUT(i, 0, ssize(ans), ans[i], "");

  return 0;
}

