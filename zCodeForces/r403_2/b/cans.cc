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
  vector<ll> X(n), V(n);
  for (ll i = 0; i < n; i++) cin >> X[i];
  for (ll i = 0; i < n; i++) cin >> V[i];
  auto check = [&](double t) -> bool {
    auto range = [&](ll j) -> pair<double, double> {
      double l = double(X[j]) - t * V[j];
      double r = double(X[j]) + t * V[j];
      return {l, r};
    };
    auto [l, r] = range(0);
    for (ll i = 1; i < n; i++) {
      auto [lx, rx] = range(i);
      l = max(l, lx);
      r = min(r, rx);
      if (r < l) return false;
    }
    return true;
  };
  double t = binsearch<double>(check, 1e9, 0, 1e-7);
  cout << t << endl;
  


  return 0;
}

