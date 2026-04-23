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
  using sta = tuple<ll, ll, ll>;
  vector<sta> ACI(N);
  REP(i, 0, N) {
    ll a, c; cin >> a >> c;
    ACI[i] = sta(a, c, i);
  }
  ranges::sort(ACI, greater<sta>());
  vector<ll> ans;
  auto [_d1, cur, i0] = ACI[0];
  ans.push_back(i0);
  REP(i, 1, N) {
    auto [a, c, idx] = ACI[i];
    if (cur > c) {
      ans.push_back(idx);
      cur = c;
    }
  }
  ranges::sort(ans);
  cout << ssize(ans) << "\n";
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  return 0;
}

