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

  ll N; cin >> N;
  ll sz = 1e5 + 10;
  vector<ll> cnt(sz);
  REP(i, N) {
    ll a; cin >> a;
    cnt[a + 1] ++;
  }
  ll ans = 0;
  REP(i, sz - 2) {
    ans = max(ans, cnt[i] + cnt[i + 1] + cnt[i + 2]);
  }
  cout << ans << endl;

  return 0;
}

