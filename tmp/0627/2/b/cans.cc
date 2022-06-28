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

  ll L, H; cin >> L >> H;
  ll N; cin >> N;
  REP(i, N) {
    ll a; cin >> a;
    ll ans = -1;
    if (a < L) ans = L - a;
    else if (a <= H) ans = 0;
    else ans = -1;
    cout << ans << endl;
  }


  return 0;
}

