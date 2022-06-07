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

  map<ll, ll> mp;
  ll Q; cin >> Q;
  REP(_q, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      mp[x]++;
    }else if (tp == 2) {
      ll x, c; cin >> x >> c;
      auto it = mp.find(x);
      if (it != mp.end()) {
        if (it->second > c) {
          it->second -= c;
        }else {
          mp.erase(it);
        }
      }
    }else if (tp == 3) {
      auto it0 = mp.begin();
      auto it1 = mp.end(); it1--;
      cout << it1->first - it0->first << "\n";
    }
  }

  return 0;
}

