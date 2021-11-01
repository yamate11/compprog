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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M; cin >> M;
  vector<vector<ll>> nbr(9);
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<ll> brd(9, -1);
  REP(i, 8) {
    ll p; cin >> p; p--;
    brd[p] = i;
  }
  ll t0 = -1;
  REP(i, 9) if (brd[i] == -1) t0 = i;
  set<vector<ll>> visited;
  auto chk = [&](auto& brd0) -> bool {
    REP(i, 8) if (brd0[i] != i) return false;
    return true;
  };
  using sta = tuple<ll, ll, vector<ll>>;
  if (chk(brd)) {
    cout << 0 << endl;
    return 0;
  }
  visited.insert(brd);
  queue<sta> que;
  sta init(0, t0, move(brd));
  que.push(move(init));
  while (not que.empty()) {
    auto z = move(que.front()); que.pop();
    auto& [cnt, t, vec] = z;
    for (ll q : nbr[t]) {
      auto newvec = vec;
      swap(newvec[q], newvec[t]);
      if (visited.find(newvec) == visited.end()) {
        visited.insert(newvec);
        if (chk(newvec)) {
          cout << cnt + 1 << endl;
          return 0;
        }
        sta newz(cnt + 1, q, move(newvec));
        que.push(move(newz));
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

