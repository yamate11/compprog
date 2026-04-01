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

  ll Q; cin >> Q;
  map<ll, ll> mp;
  ll ans = 0;
  REP(_q, 0, Q) {
    ll tp, h; cin >> tp >> h;
    if (tp == 1) {
      mp[h]++;
      ans++;
    }else if (tp == 2) {
      auto it = mp.begin();
      while (it != mp.end()) {
        if (it->first > h) break;
        ans -= it->second;
        it = mp.erase(it);
      }
    }else assert(0);
    cout << ans << "\n";
  }

  return 0;
}

