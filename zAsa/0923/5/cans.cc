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

  ll N, K; cin >> N >> K;
  ll m = (N - 1) * (N - 2) / 2 - K;
  if (m < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<pll> ans;
  REP(i, 1, N) ans.emplace_back(0, i);
  ll cnt = 0;
  REP(i, 1, N) REP(j, i + 1, N) {
    if (cnt < m) ans.emplace_back(i, j);
    cnt++;
  }
  cout << ssize(ans) << "\n";
  REP(i, 0, ssize(ans)) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
  

  return 0;
}

