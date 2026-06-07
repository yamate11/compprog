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

  ll N, M, S, G, T; cin >> N >> M >> S >> G >> T; S--; G--; T--;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [VWcF23Bd]
  struct nbr_t {
    int nd;
    ll C;
    ostream& operator<<(ostream& ostr) const {
      return ostr << "(" << nd << ", " << C << ")";
    }
    auto operator<=>(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [VWcF23Bd]

  ll big = 1LL << 60;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[G] = 0;
  pque.emplace(0, G);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        ll new_d = d + len;
        if (dist[peer] > new_d) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll ans = dist[S] + dist[T];
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

