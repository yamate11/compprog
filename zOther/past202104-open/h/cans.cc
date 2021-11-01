#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:intDiv)

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K, Q; cin >> N >> M >> K >> Q;
  vector<ll> yes, no;
  for (ll i = 0; i < N; i++) {
    ll p, t; cin >> p >> t;
    if (t == 0) no.push_back(p);
    else        yes.push_back(p);
  }
  sort(no.begin(), no.end());
  sort(yes.begin(), yes.end());
  ll t = min(M, (ll)no.size());
  ll cost = 0;
  ll k = 0;
  for (; k < t; k++) cost += no[k];
  ll i = 0;
  for (; t + i < M; i++) {
    if (i % K == 0) cost += Q;
    cost += yes[i];
  }
  ll ans = cost;
  k--;
  for (; k >= 0 && i < (ll)yes.size() && no[k] > yes[i]; k--, i++) {
    if (i % K == 0) cost += Q;
    cost += yes[i] - no[k];
    ans = min(ans, cost);
  }
  cout << ans << endl;

  return 0;
}

