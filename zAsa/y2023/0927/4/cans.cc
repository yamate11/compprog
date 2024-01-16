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

  unordered_map<ll, ll> mp;
  auto nxt = [&](auto rF, ll x) -> ll {
    if (mp.contains(x)) return mp[x];
    ll ret;
    if (x < 9) ret = x + 1;
    else if (x == 9) ret = 10;
    else {
      ll y = x % 10;
      ll t = (x - y) / 10;
      ll z = t % 10;
      if ((y < 9) and (y <= z)) {
        ret = x + 1;
      }else {
        ll a = rF(rF, t);
        ll b = a % 10;
        if (b == 0) {
          ret = a * 10;
        }else {
          ret = a * 10 + (b - 1);
        }
      }
    }
    mp[x] = ret;
    return ret;
  };

  ll K; cin >> K;
  ll ans = 1;
  REP(i, 0, K - 1) ans = nxt(nxt, ans);
  cout << ans << endl;

  return 0;
}

