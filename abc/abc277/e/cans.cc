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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  auto enc = [&](ll i, ll p) -> ll { return i * 2 + p; };
  
  vector nbr(2 * N, vector<ll>());
  REP(i, 0, M) {
    ll u, v, a; cin >> u >> v >> a; u--; v--;
    ll uu = enc(u, a);
    ll vv = enc(v, a);
    nbr[uu].push_back(vv);
    nbr[vv].push_back(uu);
  }
  vector<bool> sw(2 * N);
  REP(i, 0, K) {
    ll s; cin >> s; s--;
    sw[enc(s, 0)] = true;
    sw[enc(s, 1)] = true;
  }
  using sta = pair<ll, ll>;
  deque<sta> deq;
  deq.emplace_back(0, enc(0, 1));
  ll big = 1e18;
  vector<ll> dist(2*N, big);
  dist[enc(0, 1)] = 0;
  while (not deq.empty()) {
    auto [d, x] = deq.front(); deq.pop_front();
    if (dist[x] == d) {
      if (sw[x]) {
        ll xx = x / 2;
        ll r = x % 2;
        ll peer = xx * 2 + (1 - r);
        if (dist[peer] > dist[x]) {
          dist[peer] = dist[x];
          deq.emplace_front(dist[peer], peer);
        }
      }
      for (auto y : nbr[x]) {
        if (d + 1 < dist[y]) {
          dist[y] = d + 1;
          deq.emplace_back(d + 1, y);
        }
      }
    }
  }
  ll a = dist[enc(N - 1, 0)];
  ll b = dist[enc(N - 1, 1)];
  a = min(a, b);
  if (a >= big) a = -1;
  cout << a << endl;
  

  return 0;
}

