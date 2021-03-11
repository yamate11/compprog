#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, D; cin >> N >> X >> D;
  using stb = pair<ll, ll>;
  map<ll, stb> mp;
  if (D == 0) {
    cout << N + 1 << endl;
    return 0;
  }
  if (D < 0) {
    X = X + (N - 1) * D;
    D = -D;
  }
  using sta = pair<ll, ll>;
  vector<sta> ev;
  const ll EV_START = 0;
  const ll EV_STOP = 1;
  ev.emplace_back(0, EV_START);
  ev.emplace_back(0, EV_STOP);
  ll p = 0, q = 0;
  for (ll i = 1; i <= N; i++) {
    p += X + (i - 1) * D;
    q += X + ((N - 1) - (i - 1)) * D;
    ev.emplace_back(p, EV_START);
    ev.emplace_back(q, EV_STOP);
  }
  sort(ev.begin(), ev.end());
  ll ans = 0;
  for (auto [t, e] : ev) {
    ll m = t % D;
    auto it = mp.find(m);
    if (e == EV_START) {
      if (it == mp.end()) {
	mp[m] = {e, 1};
      }else {
	auto [start, cnt] = it->second;
	mp[m] = {start, cnt + 1};
      }
    }else {
      assert(it != mp.end());
      auto [start, cnt] = it->second;
      if (cnt == 1) {
	ans += (t - start) / D + 1;
	mp.erase(it);
      }else {
	mp[m] = {start, cnt - 1};
      }
    }
  }
  cout << ans << endl;

  return 0;
}

