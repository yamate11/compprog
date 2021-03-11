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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll _t; cin >> _t;
  for (ll _z = 0; _z < _t; _z++) {
    ll n; cin >> n;
    ll a_max = -1e10;
    ll gap_max = 0;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      updMax(a_max, a);
      ll gap = a_max - a;
      updMax(gap_max, gap);
    }
    ll k = 0;
    for (; (1LL << k) <= gap_max; k++);
    cout << k << "\n";
  }

  return 0;
}

