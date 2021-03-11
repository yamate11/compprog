#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> H(n), P(m);
  for (ll i = 0; i < n; i++) cin >> H[i];
  for (ll i = 0; i < m; i++) cin >> P[i];

  auto check = [&](ll t) -> bool {
    ll j = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      if (H[i] <= P[j]) {
	x = t;
      }else {
	ll delta = H[i] - P[j];
	if (delta > t) return false;
	ll x1 = t - 2 * delta;
	ll x2 = (t - delta) / 2;
	x = max(x1, x2);
      }
      auto it = upper_bound(P.begin(), P.end(), H[i] + x);
      if (it == P.end()) return true;
      j = it - P.begin();
    }
    return false;
  };

  ll t = binsearch<ll>(check, 1e11, -1);
  cout << t << endl;

  return 0;
}

