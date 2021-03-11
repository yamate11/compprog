#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err && abs(yes - no)/max(1.0, abs(yes)) > err ) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll m; cin >> m;
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) cin >> B[i];
  for (ll i = 0; i < n; i++) {
    if (A[i] == 1 || B[i] == 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  auto check = [&](double f) -> bool {
    for (ll i = 0; i < n; i++) {
      f = f - (m + f) / A[i];
      if (f < 0) return false;
      f = f - (m + f) / B[(i + 1) % n];
      if (f < 0) return false;
    }
    return true;
  };
  double f = binsearch<double>(check, 1.1e9, 0, 1e-7);
  cout << f << endl;

  return 0;
}

