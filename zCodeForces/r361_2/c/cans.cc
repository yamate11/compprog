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

  ll m; cin >> m;

  auto func = [&](ll t) -> ll {
    ll cnt = 0;
    ll k = 2;
    while (true) {
      ll k4 = k * k * k;
      ll x = t / k4;
      if (x == 0) break;
      cnt += x;
      k++;
    }
    return cnt;
  };

  auto check = [&](ll t) -> bool {
    return func(t) >= m;
  };

  ll t = binsearch<ll>(check, m * 8 + 100, 1);
  if (func(t) == m) {
    cout << t << endl;
  }else {
    cout << -1 << endl;
  }

  return 0;
}

