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

  ll N; cin >> N;
  string S; cin >> S;
  vector<ll> C(N), D(N);
  for (ll i = 0; i < N; i++) cin >> C.at(i);
  for (ll i = 0; i < N; i++) cin >> D.at(i);
  const ll myinf = 3010LL * (ll)(1e9);
  vector<vector<ll>> tbl(N+1, vector<ll>(N+1, myinf));
  tbl.at(0).at(0) = 0;
  for (ll i = 0; i < N; i++) {
    const vector<ll>& prev = tbl.at(i);
    vector<ll>& cur = tbl.at(i+1);
    if (S.at(i) == '(') {
      for (ll j = 0; j < N+1; j++) {
	if (j+1 < N+1) updMin(cur.at(j+1), prev.at(j));
	updMin(cur.at(j), prev.at(j) + D.at(i));
	if (j-1 >= 0) updMin(cur.at(j-1), prev.at(j) + C.at(i));
      }
    }else {
      for (ll j = 0; j < N+1; j++) {
	if (j+1 < N+1) updMin(cur.at(j+1), prev.at(j) + C.at(i));
	updMin(cur.at(j), prev.at(j) + D.at(i));
	if (j-1 >= 0) updMin(cur.at(j-1), prev.at(j));
      }
    }
  }
  cout << tbl.at(N).at(0) << endl;

  return 0;
}

