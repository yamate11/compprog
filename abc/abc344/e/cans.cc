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
  ll N; cin >> N;
  list<ll> dlist;
  map<ll, list<ll>::iterator> mp;
  REP(i, 0, N) {
    ll a; cin >> a;
    auto it = dlist.insert(dlist.end(), a);
    mp[a] = it;
  }
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y;
      mp[y] = dlist.insert(next(mp[x]), y);
    }else if (tp == 2)  {
      ll x; cin >> x;
      dlist.erase(mp[x]);
    }else assert(0);
  }
  for (ll x : dlist) cout << x << " ";
  cout << endl;
  return 0;
}

