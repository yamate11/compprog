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
  vector<ll> tri(1e4);
  REP(i, 1e4) tri[i] = i * (i + 1) / 2;
  vector<ll> rem = {1, 3, 2, 6, 4, 5};
  vector<ll> rev = {1, 5, 4, 6, 2, 3};
  ll n = N;
  ll p = 0;
  string ans;
  while (true) {
    ll i = 0;
    for (; true; i++) if (tri[i + 1] > n) break;
    REP(j, i) ans += '7';
    n -= tri[i];
    if (n == 0) break;
    p += i;
    ans += '0' + rev[p % 6];
    p++;
  }
  reverse(ALL(ans));
  cout << ans << endl;

  return 0;
}

