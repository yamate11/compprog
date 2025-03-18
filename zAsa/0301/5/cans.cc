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

  ll N; cin >> N;
  vector vec(N, vector<pll>());
  using sta = pair<ll, vector<ll>>;
  map<ll, sta> mp;
  REP(i, 0, N) {
    ll m; cin >> m;
    REP(j, 0, m) {
      ll p, e; cin >> p >> e;
      vec[i].emplace_back(p, e);
      auto it = mp.find(p);
      if (it == mp.end()) {
        mp[p] = sta(e, vector<ll>{i});
      }else {
        auto& [e1, v1] = it->second;
        if (e > e1) mp[p] = sta(e, vector<ll>{i});
        else if (e == e1) v1.push_back(i);
      }
    }
  }
  set<vector<ll>> vs;
  REP(i, 0, N) {
    vector<ll> sig;
    for (auto [p, e] : vec[i]) {
      auto& [e0, lst] = mp[p];
      if (e == e0 and ssize(lst) == 1) sig.push_back(p);
    }
    vs.insert(move(sig));
  }
  cout << ssize(vs) << endl;

  return 0;
}

