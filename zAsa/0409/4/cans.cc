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
  // @InpNbrList(N, M, nbr, dec=1) [9fB23rRq]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [9fB23rRq]

  vector<ll> val(N, -1LL);
  priority_queue<pll> pque;

  REP(i, 0, K) {
    ll p, h; cin >> p >> h; p--;
    val[p] = h;
    pque.emplace(h, p);
  }
  while (not pque.empty()) {
    auto [h, p] = pque.top(); pque.pop();
    if (val[p] == h) {
      for (ll q : nbr[p]) {
        if (val[q] < h - 1) {
          val[q] = h - 1;
          pque.emplace(h - 1, q);
        }
      }
    }
  }
  vector<ll> ans;
  REP(i, 0, N) {
    if (val[i] >= 0) ans.push_back(i);
  }
  cout << ssize(ans) << endl;
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  return 0;
}

