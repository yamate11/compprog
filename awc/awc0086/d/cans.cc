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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C, ord=(C, nd)) [vzKpMXaB]
  struct nbr_t {
    int nd;
    ll C;
    string show() const {
      return format("({}, {})", nd, C);
    }
    strong_ordering operator<=>(const nbr_t& o) const {
      if (auto r_ = C <=> o.C; r_ != 0) return r_;
      if (auto r_ = nd <=> o.nd; r_ != 0) return r_;
      return std::strong_ordering::equal;
    }
    bool operator==(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [vzKpMXaB]

  ll big = 1LL << 60;
  vector<ll> dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        ll new_d = d + len;
        if (new_d < dist[peer]) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll ans = dist[N - 1];
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

