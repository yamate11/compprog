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

  ll N, Q; cin >> N >> Q;
  vector<set<ll>> vec(N);
  vector<bool> conn(N);
  ll ans = N;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll u, v; cin >> u >> v; u--; v--;
      if (not conn[u]) { conn[u] = true; ans--; }
      if (not conn[v]) { conn[v] = true; ans--; }
      vec[u].insert(v);
      vec[v].insert(u);
    }else if (tp == 2) {
      ll v; cin >> v; v--;
      if (conn[v]) {
        for (ll i : vec[v]) {
          vec[i].erase(v);
          if (vec[i].empty()) { conn[i] = false; ans++; }
        }
        vec[v] = set<ll>();
        conn[v] = false; ans++;
      }
    }else assert(0);
    cout << ans << "\n";
  }

  return 0;
}

