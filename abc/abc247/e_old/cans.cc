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

  ll N, X, Y; cin >> N >> X >> Y;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  if (X == Y) {
    ll ans = 0;
    ll i = 0;
    while (i < N) {
      while (i < N and (A[i] != X)) i++;
      if (i == N) break;
      ll t = i;
      while (i < N and (A[i] == X)) i++;
      ll m = i - t;
      ans += m * (m + 1) / 2;
    }
    cout << ans << endl;
    return 0;
  }
  auto func = [&](ll s, ll t) -> ll {
    ll ret = 0;
    ll i = s;
    bool bY = false, bX = false;
    ll p;
    ll j = i;
    for ( ; j <= t; j++) {
      if (A[j] == Y) {
        if (bX) {
          ret += (p - i + 1) * (t - j + 1);
          i = p + 1;
          p = j;
          bX = false;
          bY = true;
        }else {
          bY = true;
          p = j;
        }
      }else if (A[j] == X) {
        if (bY) {
          ret += (p - i + 1) * (t - j + 1);
          i = p + 1;
          p = j;
          bY = false;
          bX = true;
        }else {
          bX = true;
          p = j;
        }
      }
    }
    return ret;
  };
  ll ans = 0;
  ll i = 0;
  while (i < N) {
    while (i < N and (A[i] < Y or X < A[i])) i++;
    if (i == N) break;
    ll t = i;
    while (i < N and (Y <= A[i] and A[i] <= X)) i++;
    ans += func(t, i - 1);
  }
  cout << ans << endl;

  return 0;
}

