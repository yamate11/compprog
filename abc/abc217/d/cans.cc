#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L, Q; cin >> L >> Q;
  set<ll> P;
  P.insert(0);
  P.insert(L);
  for (; Q > 0; Q--) {
    ll c, x; cin >> c >> x;
    if (c == 1) {
      P.insert(x);
    }else if (c == 2) {
      auto it = P.lower_bound(x);
      ll upper = *it;
      it--;
      ll lower = *it;
      cout << upper - lower << "\n";
    }
  }
  

  return 0;
}

