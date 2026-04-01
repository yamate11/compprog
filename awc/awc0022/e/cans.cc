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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [AbcvuBma]
  struct nbr_t {
    int nd;
    ll W;
    nbr_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [AbcvuBma]

  ll big = 1e18;
  vector tbl(1LL << N, vector(N, big));
  using sta = pair<ll, pll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  tbl[0][0] = 0;
  pque.emplace(0, pll(0, 0));
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    auto [x, t] = nd;
    if (tbl[x][t] == d) {
      for (auto [s, w] : nbr[t]) {
        ll y = x | (1LL << s);
        if (tbl[y][s] > d + w) {
          tbl[y][s] = d + w;
          pque.emplace(d + w, pair(y, s));
        }
      }
    }
  }
  ll full = (1LL << N) - 1;
  ll ans = tbl[full][0];
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

