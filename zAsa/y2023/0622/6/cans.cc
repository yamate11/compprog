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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [5Cbu3glG]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [5Cbu3glG]
  ll K; cin >> K;
  // @InpVec(K, C, dec=1) [tXOdJuAm]
  auto C = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [tXOdJuAm]
  
  ll big = 1e18;
  vector dist(K, vector(K, big));
  REP(k, 0, K) {
    queue<ll> que;
    vector<ll> locdist(N, big);
    locdist[C[k]] = 0;
    que.push(C[k]);
    while (not que.empty()) {
      ll nd = que.front(); que.pop();
      for (ll peer : nbr[nd]) {
        if (locdist[peer] == big) {
          locdist[peer] = locdist[nd] + 1;
          que.push(peer);
        }
      }
    }
    REP(i, 0, K) dist[k][i] = locdist[C[i]];
  }

  vector fdist(1LL << K, vector(K, big));
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  REP(i, 0, K) {
    fdist[1LL << i][i] = 1;
    pque.emplace(1, 1LL << i, i);
  }
  while (not pque.empty()) {
    auto [d, ndx, ndi] = pque.top(); pque.pop();
    if (d != fdist[ndx][ndi]) continue;
    REP(j, 0, K) {
      if (ndi == j) continue;
      ll newD = d + dist[ndi][j];
      ll newX = ndx | (1LL << j);
      if (newD < fdist[newX][j]) {
        fdist[newX][j] = newD;
        pque.emplace(newD, newX, j);
      }
    }
  }
  ll ans = big;
  REP(i, 0, K) ans = min(ans, fdist[(1LL << K) - 1][i]);
  if (ans == big) ans = -1;
  cout << ans << endl;


  return 0;
}

