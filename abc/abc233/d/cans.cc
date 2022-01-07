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

  ll N, K; cin >> N >> K;
  map<ll, ll> mp;
  mp[0] = 1;
  ll s = 0;
  ll ans = 0;
  REP(i, N) {
    ll a; cin >> a;
    s += a;
    ll p = s - K;
    ans += mp[p];
    // if (K == 0 && a == 0) ans++;
    mp[s] += 1;
  }
  cout << ans << endl;

  return 0;
}

