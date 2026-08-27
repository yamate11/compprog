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
  map<ll, vector<ll>> mp;
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  set<ll> visited;
  queue<ll> que;
  visited.insert(1);
  que.push(1);
  ll ans = 1;
  while (not que.empty()) {
    ll x = que.front(); que.pop();
    ans = max(ans, x);
    auto it = mp.find(x);
    if (it != mp.end()) {
      for (ll y : it->second) {
        auto [it2, b] = visited.insert(y);
        if (b) {
          que.push(y);
        }
      }
    }
  }
  cout << ans << "\n";

  return 0;
}

