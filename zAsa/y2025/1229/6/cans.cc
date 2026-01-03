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

  ll N, M, S, T; cin >> N >> M >> S >> T; S--; T--;
  vector nbrA(N, vector<pll>());
  vector nbrB(N, vector<pll>());
  REP(i, 0, M) {
    ll u, v, a, b; cin >> u >> v >> a >> b; u--; v--;
    nbrA[u].emplace_back(v, a);
    nbrA[v].emplace_back(u, a);
    nbrB[u].emplace_back(v, b);
    nbrB[v].emplace_back(u, b);
  }
  ll big = 1e15;
  auto f = [&](ll start, const auto& nbr) -> vector<ll> {
    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[start] = 0;
    pque.emplace(0, start);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [peer, len] : nbr[nd]) {
          if (dist[peer] > d + len) {
            dist[peer] = d + len;
            pque.emplace(d + len, peer);
          }
        }
      }
    }
    return dist;
  };

  auto vecA = f(S, nbrA);
  auto vecB = f(T, nbrB);
  vector<ll> ans(N);
  ll cur = big;
  REPrev(i, N - 1, 0) {
    cur = min(cur, vecA[i] + vecB[i]);
    ans[i] = cur;
  }
  REPOUT(i, 0, N, big - ans[i], "\n");

  return 0;
}

