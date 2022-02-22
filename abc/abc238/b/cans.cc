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
  vector<ll> rec;
  rec.push_back(0);
  ll t = 0;
  REP(i, N) {
    ll a; cin >> a;
    t += a;
    if (t >= 360) t -= 360;
    rec.push_back(t);
  }
  rec.push_back(360);
  sort(ALL(rec));
  ll ans = 0;
  for (ll i = 0; i < SIZE(rec) - 1; i++) {
    ans = max(ans, rec[i + 1] - rec[i]);
  }
  cout << ans << endl;

  return 0;
}

