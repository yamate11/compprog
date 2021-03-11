#include <bits/stdc++.h>
#include <cassert>
#include <atcoder/dsu>
typedef long long int ll;
using namespace std;
using namespace atcoder;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  dsu d(N);
  for (ll _q = 0; _q < Q; _q++) {
    ll t, u, v; cin >> t >> u >> v;
    if (t == 0) d.merge(u, v);
    else {
      cout << (d.same(u, v) ? 1 : 0) << "\n";
    }
  }


  return 0;
}

