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

  ll a, b; cin >> a >> b;
  u64 C; cin >> C;
  ll c = popcount(C);
  ll xx = a + b - c;
  if (xx % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll x = xx / 2;
  ll y = a - x;
  ll z = b - x;
  ll w = 60 - (x + y + z);
  if (not (0 <= x and x <= 60 and 0 <= y and y <= 60 and 0 <= z and z <= 60 and 0 <= w and w <= 60)) {
    cout << -1 << endl;
    return 0;
  }
  u64 ans1 = 0, ans2 = 0;
  REP(i, 0, 60) {
    if (C >> i & 1) {
      if (y > 0) {
        ans1 |= (1LL << i);
        y--;
      }else {
        ans2 |= (1LL << i);
      }
    }else {
      if (x > 0) {
        ans1 |= (1LL << i);
        ans2 |= (1LL << i);
        x--;
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;

  return 0;
}

