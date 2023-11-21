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

  ll N, Q; cin >> N >> Q;
  map<ll, set<ll>> mp;
  REP(_q, 0, Q) {
    ll t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      mp[a].insert(b);
    }else if (t == 2) {
      mp[a].erase(b);
    }else if (t == 3) {
      bool res = mp[a].contains(b) and mp[b].contains(a);
      cout << (res ? "Yes\n" : "No\n");
    }else assert(0);
  }

  return 0;
}

