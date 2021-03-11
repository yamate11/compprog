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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector H(N, 0LL);
  for (ll i = 0; i < N; i++) cin >> H[i];
  vector r(H);
  r.push_back(0);
  sort(r.begin(), r.end());
  auto last = unique(r.begin(), r.end());
  r.resize(last - r.begin());
  ll rsz = r.size();
  ll big = 1e15;
  vector cur(rsz, vector(K + 1, big));
  cur[0][0] = 0;
  for (ll i = 0; i < N; i++) {
    vector nxt(rsz, vector(K + 1, big));
    ll j0 = lower_bound(r.begin(), r.end(), H[i]) - r.begin();
    for (ll j = 0; j < rsz; j++) {
      for (ll k = 0; k <= K; k++) {
	ll w = max(H[i] - r[j], 0LL);
	updMin(nxt[j0][k], cur[j][k] + w);
	if (k + 1 <= K) updMin(nxt[j][k + 1], cur[j][k]);
      }
    }
    cur = move(nxt);
  }
  ll ans = big;
  for (ll j = 0; j < rsz; j++) {
    for (ll k = 0; k <= K; k++) updMin(ans, cur[j][k]);
  }
  cout << ans << endl;

  return 0;
}

