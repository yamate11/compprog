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

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1, read=A) [Dm2HTX28]
  struct nbr_t {
    int nd;
    ll A;
    ostream& operator<<(ostream& ostr) const {
      return ostr << "(" << nd << ", " << A << ")";
    }
    auto operator<=>(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll A; cin >> A;
    nbr[u].emplace_back(v, A);
    nbr[v].emplace_back(u, A);
  }
  // @End [Dm2HTX28]
  // @InpVec(K, S, dec=1) [cPc8EiMi]
  auto S = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; S[i] = v; }
  // @End [cPc8EiMi]
  vector rble(N, false);
  REP(i, 0, K) rble[S[i]] = true;
  
  ll big = 1LL << 60;
  vector dist(2, vector(N, big));
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  dist[0][0] = 0;
  pque.emplace(0, 0, 0);
  while (not pque.empty()) {
    auto [d, b, n] = pque.top(); pque.pop();
    if (dist[b][n] == d) {
      if (rble[n]) {
        if (dist[1 - b][n] > d) {
          dist[1 - b][n] = d;
          pque.emplace(d, 1-b, n);
        }
      }
      for (auto [p, a] : nbr[n]) {
        if ((a == 1) == (b == 0)) {
          if (dist[b][p] > d + 1) {
            dist[b][p] = d + 1;
            pque.emplace(d + 1, b, p);
          }
        }
      }
    }
  }
  ll ans = min(dist[0][N - 1], dist[1][N - 1]);
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

