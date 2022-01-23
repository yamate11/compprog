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

  ll N, M; cin >> N >> M;
  vector<vector<ll>> fwd(N);
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    fwd[u].push_back(v);
  }
  vector<bool> visited(N);
  // vector<ll> stack;
  vector<bool> on_stack(N);
  auto dfs = [&](auto rF, ll nd) -> void {
    if (on_stack[nd]) throw myexc();
    if (visited[nd]) return;
    visited[nd] = true;
    on_stack[nd] = true;
    // stack.push_back(nd);
    for (ll f : fwd[nd]) rF(rF, f);
    // stack.pop_back();
    on_stack[nd] = false;
  };
  try {
    REP(nd, N) {
      if (visited[nd]) continue;
      dfs(dfs, nd);
    }
    cout << "No\n";
  }catch(myexc& e) {
    cout << "Yes\n";
  }

  return 0;
}

