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

  ll K; cin >> K;
  using sta = pair<ll, ll>;
  deque<sta> deq;
  const ll big = 1e10;
  vector<ll> dist(K, big);
  dist[1] = 1;
  deq.emplace_back(1, 1);
  while (not deq.empty()) {
    auto [d, n] = deq.front(); deq.pop_front();
    if (dist[n] < d) continue;
    if (n == 0) {
      cout << d << endl;
      return 0;
    }
    ll y = (n + 1) % K;
    if (d + 1 < dist[y]) {
      dist[y] = d + 1;
      deq.emplace_back(d + 1, y);
    }
    y = (10 * n) % K;
    if (d < dist[y]) {
      dist[y] = d;
      deq.emplace_front(d, y);
    }
  }

  return 0;
}

