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

  ll N, Q; cin >> N >> Q;
  vector<set<ll>> nbr(N);
  ll cur = N;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll u, v; cin >> u >> v; u--; v--;
      if (nbr[u].empty()) cur--;
      if (nbr[v].empty()) cur--;
      nbr[u].insert(v);
      nbr[v].insert(u);
    }else if (tp == 2) {
      ll u; cin >> u; u--;
      if (not nbr[u].empty()) cur++;
      for (ll v : nbr[u]) {
        nbr[v].erase(u);
        if (nbr[v].empty()) cur++;
      }
      nbr[u].clear();
    }
    cout << cur << "\n";
  }

  return 0;
}

