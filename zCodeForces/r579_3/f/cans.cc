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

  auto solve = [&]() -> ll {
    ll N, rate; cin >> N >> rate;
    using sta = pair<ll, ll>;
    vector<sta> pos, zero, neg;
    ll sumpos = 0;
    ll sumneg = 0;
    for (ll i = 0; i < N; i++) {
      ll a, b; cin >> a >> b;
      if (b > 0) {
	sumpos += b;
	pos.emplace_back(a, b);
      }
      else if (b == 0) zero.emplace_back(a, 0);
      else {
	sumneg -= b;
	neg.emplace_back(a + b, -b);
      }
    }
    if (rate + sumpos - sumneg < 0) return false;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<sta>());
    ll cnt = 0;

    for (auto [a, b] : pos) {
      if (rate < a) break;
      rate += b;
      cnt++;
    }
    for (auto [a, b] : zero) {
      if (rate < a) break;
      cnt++;
    }
    ll m = neg.size();
    vector<ll> cur(m + 1);
    cur[0] = rate;
    for (ll i = 0; i < m; i++) {
      auto prev(cur);
      auto [u, v] = neg[i];
      ll a = u + v, b = -v;
      for (ll k = 0; k <= m; k++) {
	if (k+1 <= m && prev[k] >= a) updMax(cur[k+1], prev[k] + b);
      }
    }
    for (ll i = m; i >= 0; i--) {
      if (cur[i] >= 0) {
	cnt += i;
	break;
      }
    }
    return cnt;
  };

  cout << solve() << endl;

  return 0;
}

