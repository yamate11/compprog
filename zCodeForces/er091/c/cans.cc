#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:intDiv)
// --> f:intDiv
// ---- inserted function intDiv from util.cc
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

// ---- end intDiv
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());
    ll d = 1;
    ll i = 0;
    ll cnt = 0;
    ll s = 0;
    while (i < N) {
      while (i < N && s < d && A[i] >= divCeil(X, d)) {
	s++;
	i++;
      }
      if (s == d) {
	cnt++;
	s = 0;
      }else {
	if (d * d < X) d++;
	else {
	  ll r = divCeil(X, d);
	  if (r == 1) break;
	  d = divCeil(X, r - 1);
	}
      }
    }
    cout << cnt << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

