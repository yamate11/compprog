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

  ll N, M; cin >> N >> M:
  // @InpVec(N, P) [3wZBtdlV]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [3wZBtdlV]
  vector<ll> nbr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  // @InpVec(M, C, dec=1) [3rEIGZzm]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [3rEIGZzm]
  ll big = 1e18;
  vector dist(N, big);
  queue<ll> que;
  REP(i, 0, M) {
    dist[C[i]] = 0;
    que.push(C[i]);
  }
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll peer : nbr[nd]) {
      if (dist[peer] == big) {
        dist[peer] = dist[nd] + 1;
        que.push(peer);
      }
    }
  }
  vector live(N, true);
  vector rem(N, vector<ll>());
  priority_queue<pll> pque;
  REP(i, 0, N) {
    if (ssize(nbr[i]) == 1 and dist[i] > 0) pque.emplace(P[i], i);
  }
  ll ans = 0;
  ll tm = 0;
  while (true) {
    auto get_leaf = [&]() -> pll {
      while (not pque.empty()) {
        auto [pur, nd] = pque.top(); pque.pop();
        if (dist[nd] > tm) return pll(pur, nd);
      }
      return pll(-1, -1);
    };
    auto [pur, nd] = get_leaf();
    if (pur < 0) break;
    ans += pur;
    live[nd] = false;
    sort(ALL(nbr[nd]));
    sort(ALL(rem[nd]));
    REP(i, 0, ssize(nbr[nd])) {
      if (i >= ssize(rem[nd]) or nbr[nd][i] != rem[nd][i]) {
        ll peer = nbr[nd][i];
        if (live[peer]) {
          rem[peer].push_back(nd);
          if (ssize(rem[peer]) + 1 == ssize(nbr[peer])) {
            pque.emplace(P[peer], peer);
          }
        }
      }
    }
    tm++;
  }
  cout << ans << endl;

  return 0;
}

