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

// @@ !! LIM(bellmanford)

// ---- inserted library file bellmanford.cc

struct BellmanFord {
  const ll big = 2e18; // should not be LLONG_MAX to detect negative cycles
  ll n;
  vector<tuple<ll, ll, ll>> fwd;
  vector<ll> dist;
  BellmanFord(ll n_) : n(n_), fwd{}, dist(n, big) {}
  void add_edge(ll from, ll to, ll cost) { fwd.emplace_back(from, to, cost); }
  bool _update() {
    bool ret = false;
    for (auto [from, to, cost] : fwd) {
      if (dist[from] + cost < dist[to]) {
        ret = true;
        dist[to] = dist[from] + cost;
      }
    }
    return ret;
  }
  bool run(ll start) {
    dist[start] = 0;
    if (fwd.empty()) return true;
    // Changes can occur (n - 1) times (the length of the path).  In that case, the stable state can only be detected
    // at the n-th update.
    for(ll _r = 0; _r < n; _r++) if (not _update()) return true;
    return false;
  }
};

struct UshiGame {
  ll n;
  BellmanFord bf;
  UshiGame(ll n_) : n(n_), bf(n_) {}

  // v_to - v_from <= c
  void add_constrLE(ll from, ll to, ll c) { bf.add_edge(from, to, c); }

  // v_to - v_from >= c
  void add_constrGE(ll from, ll to, ll c) { add_constrLE(to, from, -c); }
  
  // maximize v_from - v_to
  optional<ll> getmax(ll from, ll to) {
    bool b = bf.run(from);
    if (not b) return nullopt;
    else return bf.dist[to];
  }

  // minimize v_from - v_to
  optional<ll> getmin(ll from, ll to) {
    bool b = bf.run(to);
    if (not b) return nullopt;
    else return -bf.dist[from];
  }
};


// ---- end bellmanford.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  UshiGame ug(N + 1);
  REP(i, 0, M) {
    ll l, r, x; cin >> l >> r >> x; l--;
    ug.add_constrGE(l, r, x);
  }
  REP(i, 0, N) {
    ug.add_constrGE(i, i + 1, 0);
    ug.add_constrLE(i, i + 1, 1);
  }
  ug.getmin(0, N);
  vector<ll> ans(N);
  REP(i, 0, N) {
    ans[i] = ug.bf.dist[i + 1] - ug.bf.dist[i];
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

