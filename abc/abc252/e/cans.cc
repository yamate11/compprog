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

  ll N, M; cin >> N >> M;
  map<ll, map<ll, ll>> roadnum;
  using Pair = pair<ll, ll>;
  vector<vector<Pair>> nbr(N);
  REP(i, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    nbr[a].emplace_back(b, c);
    nbr[b].emplace_back(a, c);
    roadnum[a][b] = i + 1;
    roadnum[b][a] = i + 1;
  }
  const ll big = 1e18;
  vector<ll> dist(N, big);
  vector<ll> prev(N, -1);
  vector<ll> ans;
  using sta = pair<ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  pque.emplace(0, 0);
  dist[0] = 0;
  while (not pque.empty()) {
    auto [d, x] = pque.top(); pque.pop();
    if (dist[x] < d) continue;
    if (x > 0) ans.push_back(roadnum[x][prev[x]]);
    for (auto [xx, dd] : nbr[x]) {
      ll newD = d + dd;
      if (newD >= dist[xx]) continue;
      dist[xx] = newD;
      prev[xx] = x;
      pque.emplace(newD, xx);
    }
  }
  for (ll m : ans) cout << m << " ";
  cout << endl;

  return 0;
}

