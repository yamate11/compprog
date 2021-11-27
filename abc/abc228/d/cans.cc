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

  ll N = 1LL << 20;
  ll Q; cin >> Q;
  set<ll> remain;
  REP(i, N) remain.insert(i);
  vector<ll> vec(N, -1);
  REP(_q, Q) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      ll h = x % N;
      auto it = remain.lower_bound(h);
      if (it == remain.end()) {
        it = remain.lower_bound(0);
      }
      ll i = *it;
      vec[i] = x;
      remain.erase(it);
    }else if (t == 2) {
      cout << vec[x % N] << "\n";
    }
  }

  return 0;
}

