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
  vector<sta> CAI;
  REP(i, 0, N) {
    ll a, c; cin >> a >> c;
    CAI.emplace_back(c, a, i);
  }
  sort(ALL(CAI), [&](sta x, sta y) -> bool {
    auto [xc, xa, xi] = x;
    auto [yc, ya, yi] = y;
    return xa < ya;
  });
  priority_queue<sta> pque;
  for (auto [c, a, i] : CAI) {
    while (not pque.empty()) {
      auto [pc, pa, pi] = pque.top();
      if (pc < c) break;
      pque.pop();
    }
    pque.emplace(c, a, i);
  }
  vector<ll> ans;
  while (not pque.empty()) {
    auto [c, a, i] = pque.top(); pque.pop();
    ans.push_back(i);
  }
  sort(ALL(ans));
  cout << ssize(ans) << endl;
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  
  

  return 0;
}

