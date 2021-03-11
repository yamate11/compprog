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

  ll N, L; cin >> N >> L;
  vector<bool> haz(L+1);
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x;
    haz.at(x) = true;
  }
  ll T1, T2, T3; cin >> T1 >> T2 >> T3;
  vector<ll> tbl(L+1, LLONG_MAX);
  tbl.at(0) = 0;

  auto pen = [&](ll j) -> ll { return haz.at(j) ? T3 : 0; };

  for (ll i = 0; i < L; i++) {
    ll t = tbl.at(i);
    updMin(tbl.at(i+1), t + T1 + pen(i+1));
    if (i+2 <= L) {
      updMin(tbl.at(i+2), t + T1 + T2 + pen(i+2));
    }else {
      updMin(tbl.at(L), t + (T1 + T2) / 2);
    }
    if (i+4 <= L) {
      updMin(tbl.at(i+4), t + T1 + 3 * T2 + pen(i+4));
    }else {
      updMin(tbl.at(L), t + T1/2 + T2/2 + (L - i - 1) * T2);
    }
  }
  cout << tbl.at(L) << endl;
  return 0;
}

