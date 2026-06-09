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

  ll n; cin >> n;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    sum += a;
  }
  auto check = [&](ll x) -> bool {
    return n * (2 * x + n - 1) / 2 <= sum;
  };
  ll x = binsearch<ll>(check, 0, 1 + sum / n);
  ll t = sum - n * (2 * x + n - 1) / 2;
  bool first = true;
  for (ll i = 0; i < n; i++) {
    if (first) first = false;
    else cout << " ";
    ll y = i < t ? x + i + 1 : x + i;
    cout << y;
  }
  cout << endl;

  return 0;
}

