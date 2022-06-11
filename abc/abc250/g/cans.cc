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
  vector<ll> P(N); REP(i, N) cin >> P[i];
  using pll = pair<ll, ll>;
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  ll ans = 0;
  REP(i, N) {
    if (i == 0) {
      pque.emplace(P[0], 1);
      continue;
    }
    auto [v, tp] = pque.top();
    if (P[i] <= v) {
      pque.emplace(P[i], 1);
    }else {
      ans += P[i] - v;
      pque.pop();
      if (tp == 2) pque.emplace(v, 1);
      pque.emplace(P[i], 2);
    }
  }
  cout << ans << endl;
  return 0;
}

