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

  ll N, M, S; cin >> N >> M >> S; S--;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [fzI2kG6J]
  struct nbr_t {
    int nd{};
    ll W{};
    string show() const {
      return "(" + to_string(nd) + ", " + to_string(W) + ")";
    }
    bool operator==(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [fzI2kG6J]

  ll big = 1LL << 60;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[S] = 0;
  pque.emplace(0, S);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        if (d + len < dist[peer]) {
          dist[peer] = d + len;
          pque.emplace(d + len, peer);
        }
      }
    }
  }
  ll ans = 0;
  REP(i, 0, N) {
    if (dist[i] < big) ans += dist[i];
  }
  cout << ans << "\n";
  return 0;
}

