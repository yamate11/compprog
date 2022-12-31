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

  auto g = [&](ll x, bool b) -> ll {
    vector<ll> vec;
    while (x > 0) {
      vec.push_back(x % 10);
      x /= 10;
    }
    if (b) sort(ALL(vec), greater<ll>());
    else sort(ALL(vec));
    ll ret = 0;
    for (ll v : vec) ret = 10 * ret + v;
    return ret;
  };
  auto f = [&](ll x) -> ll { return g(x, true) - g(x, false); };

  ll N, K; cin >> N >> K;
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }else {
    ll ans = N;
    REP(k, K) ans = f(ans);
    cout << ans << endl;
  }
  
  

  return 0;
}

