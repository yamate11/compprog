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

  ll n, k; cin >> n >> k;
  ll lim = 2e5;
  vector rec(lim + 1, 0LL);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    rec[a]++;
  }
  /*
  vector vec;
  for (ll i = 1; i <= lim; i++) {
    if (rec[i] > 0) vec.push_back(rec[i]);
  }
  sort(vec.begin(), vec.end(), greater<ll>());
  */
  auto check = [&](ll t) -> bool {
    ll x = 0;
    for (ll i = 1; i <= lim; i++) {
      x += rec[i] / t;
    }
    return x >= k;
  };
  ll t = binsearch<ll>(check, 1, n + 1);
  bool first = true;
  ll cnt = 0;
  for (ll i = 1; i <= lim; i++) {
    ll c = rec[i] / t;
    if (c > 0) {
      for (ll j = 0; j < c; j++) {
	if (first) first = false;
	else cout << " ";
	cout << i;
	cnt++;
	if (cnt == k) break;
      }
    }
    if (cnt == k) break;
  }
  cout << endl;

  return 0;
}

