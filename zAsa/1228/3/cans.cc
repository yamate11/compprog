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

  map<ll, ll> mp;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      mp[x]++;
    }else if (tp == 2) {
      ll x, c; cin >> x >> c;
      ll n = mp[x];
      ll new_n = n - min(c, n);
      if (new_n == 0) {
        mp.erase(x);
      }else {
        mp[x] = new_n;
      }
    }else if (tp == 3) {
      cout << prev(mp.end())->first - mp.begin()->first << "\n";
    }else assert(0);
  }

  return 0;
}

