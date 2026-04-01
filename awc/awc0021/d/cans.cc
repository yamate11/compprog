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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1, read=T) [k0r8PRIb]
  struct nbr_t {
    int nd;
    ll T;
    nbr_t(int nd_ = int(), ll T_ = ll()) : nd(nd_), T(T_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll T; cin >> T;
    nbr[u].emplace_back(v, T);
    nbr[v].emplace_back(u, T);
  }
  // @End [k0r8PRIb]


  ll big = 1e18;
  auto f = [&](ll s, ll t) -> ll {
    vector dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[s] = 0;
    pque.emplace(0, s);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (d == dist[nd]) {
        for (auto [peer, len] : nbr[nd]) {
          ll new_d = d + len;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    return dist[t];
  };

  vector<ll> P{0};
  REP(i, 0, K) {
    ll p; cin >> p; p--;
    P.push_back(p);
  }
  P.push_back(N - 1);
  ll ans = 0;
  REP(i, 0, ssize(P) - 1) {
    ll x = f(P[i], P[i + 1]);
    if (x == big) {
      cout << -1 << endl;
      return 0;
    }else {
      ans += x;
    }
  }
  cout << ans << endl;

  return 0;
}

