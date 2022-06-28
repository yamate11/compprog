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
  ll lim = 1e5;
  vector c(lim + 1, 0LL);
  REP(i, N) {
    ll a; cin >> a;
    c[a]++;
  }
  ll cnt1 = 0;
  ll cnt2 = 0;
  REP(i, lim + 1) {
    if (c[i] > 0) cnt1++;
    if (c[i] > 1) cnt2 += c[i] - 1;
  }
  ll ans = (cnt2 % 2 == 0) ? cnt1 : cnt1 - 1;
  cout << ans << endl;

  return 0;
}

