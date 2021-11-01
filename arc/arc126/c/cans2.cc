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

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll amax = A[N-1];
  ll bdr = llround(sqrt(amax));
  ll ans = 1;
  ll d;
  for (ll m = 1; m <= bdr; m++) {
    ll s = 0;
    d = divCeil(amax, m);
    ll c = 1;
    ll step = 0;
    for (ll i = 0; i < N; i++) {
      while (A[i] > c * d) c++;
      step += c;
      s += c * d - A[i];
    }
    if (s > K) continue;
    ll dd = d + divFloor(K - s, step);
    ans = max(ans, dd);
  }
  d--;
  for (; d >= 2; d--) {
    ll s = 0;
    ll c = 1;
    ll step = 0;
    for (ll i = 0; i < N; i++) {
      while (A[i] > c * d) c++;
      step += c;
      s += c * d - A[i];
    }
    if (s > K) continue;
    ll dd = d + divFloor(K - s, step);
    ans = max(ans, dd);
  }
  cout << ans << endl;

  return 0;
}

