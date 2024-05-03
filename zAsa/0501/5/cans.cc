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
  // @InpNbrList(N, M, fwd, dec=1, dir=True) [gmtnuvbN]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [gmtnuvbN]
  REP(i, 0, N) sort(ALL(fwd[i]), greater<ll>());

  vector<ll> tbl{-1LL};
  REP(i, 0, N) {
    for (ll x : fwd[i]) {
      if (tbl.back() < x) { tbl.push_back(x); }
      else {
        ll j = lower_bound(ALL(tbl), x) - tbl.begin();
        if (x < tbl[j]) tbl[j] = x;
      }
    }
  }
  cout << ssize(tbl) - 1 << endl;

  return 0;
}

