#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  ll N, M; cin >> N >> M;
  ll big = ll(1e5 + 10) * (M + 10);
  vector<ll> val(1<<N, big);
  val[0] = 0;
  for (ll i = 0; i < M; i++) {
    vector<ll> prev(val);
    ll a, b; cin >> a >> b;
    ll x = 0;
    for (ll j = 0; j < b; j++) {
      ll c; cin >> c; c--;
      x |= (1 << c);
    }
    for (ll y = 0; y < (1<<N); y++) {
      updMin(val[y | x], prev[y] + a);
    }
  }
  ll k = val[(1<<N) - 1];
  cout << (k >= big ? -1 : k) << endl;

  return 0;
}

