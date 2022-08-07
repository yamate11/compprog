#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll S, T, M; cin >> S >> T >> M;
  vector nbr(S + T, vector<ll>());
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  REP(i, S + T) sort(ALL(nbr[i]));
  REP2(q, S, S + T) {
    map<ll, ll> cands;
    for (ll p : nbr[q]) {
      auto it = upper_bound(ALL(nbr[p]), q);
      if (it == nbr[p].end()) continue;
      ll q1 = *it;
      auto itc = cands.find(q1);
      if (itc != cands.end()) {
        cout << q + 1 << " " << q1 + 1 << " " << p + 1 << " " << itc->second + 1 << "\n";
        return 0;
      }
      cands[q1] = p;
    }
    while (not cands.empty()) {
      auto itb = cands.begin();
      auto [q1, p1] = *itb;
      cands.erase(itb);
      auto it = upper_bound(ALL(nbr[p1]), q1);
      if (it == nbr[p1].end()) continue;
      ll q2 = *it;
      auto itc = cands.find(q2);
      if (itc != cands.end()) {
        cout << q + 1 << " " << q2 + 1 << " " << p1 + 1 << " " << itc->second + 1 << "\n";
        return 0;
      }
      cands[q2] = p1;
    }
  }
  cout << -1 << "\n";

  return 0;
}

