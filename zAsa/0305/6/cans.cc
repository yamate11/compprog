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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=(C, D)) [i8nj2lRO]
  struct nbr_t {
    int nd;
    ll C;
    ll D;
    nbr_t(int nd_ = int(), ll C_ = ll(), ll D_ = ll()) : nd(nd_), C(C_), D(D_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    ll D; cin >> D;
    nbr[u].emplace_back(v, C, D);
    nbr[v].emplace_back(u, C, D);
  }
  // @End [i8nj2lRO]

  auto calc = [&](ll t, ll d) -> ll {
    auto f = [&](double w) -> double { return w + d / (t + w + 1); };
    double lo = 0;
    double hi = d;
    REP(rep, 0, 120) {
      double mid1 = lo + (hi - lo) / 3.0;
      double mid2 = hi - (hi - lo) / 3.0;
      double t1 = f(mid1);
      double t2 = f(mid2);
      if (t1 < t2) hi = mid2;
      else lo = mid1;
    }
    return llround(floor(f(lo)));
  };

  ll big = 1e18;
  vector time(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  time[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [t, nd] = pque.top(); pque.pop();
    if (time[nd] == t) {
      for (auto [p, c, d] : nbr[nd]) {
        ll new_t = t + c + calc(t, d);
        if (new_t < time[p]) {
          time[p] = new_t;
          pque.emplace(new_t, p);
        }
      }
    }
  }
  if (time[N - 1] == big) cout << -1 << endl;
  else cout << time[N - 1] << endl;

  return 0;
}

