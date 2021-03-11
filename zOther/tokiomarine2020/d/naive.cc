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
  vector<ll> V(N+1), W(N+1);
  for (ll i = 1; i <= N; i++) {
    cin >> V.at(i) >> W.at(i);
  }
  ll Q; cin >> Q;
  for (ll _q = 0; _q < Q; _q++) {
    ll v, L; cin >> v >> L;

    vector<ll> val;
    vector<ll> weight;
    ll t = 0;
    for (ll v1 = v; v1 > 0; v1 >>= 1) {
      t++;
      val.push_back(V.at(v1));
      weight.push_back(W.at(v1));
    }
    ll ans = 0;
    for (ll x = 0; x < (1<<t); x++) {
      ll vv = 0;
      ll ww = 0;
      for (ll i = 0; i < t; i++) {
	if ((x >> i) & 1) {
	  vv += val.at(i);
	  ww += weight.at(i);
	}
      }
      if (ww > L) continue;
      updMax(ans, vv);
    }

    cout << ans << "\n";
  }

  return 0;
}

