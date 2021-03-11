#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll r, n; cin >> r >> n;
  vector<ll> t(n), x(n), y(n);
  for (ll i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  using sta = tuple<ll, ll, ll, ll>;
  set<sta> rec;
  rec.emplace(0, 0, 1, 1);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    auto it = rec.begin();
    while (true) {
      if (it == rec.end()) {
	break;
      }
      auto [mnum, tt, xx, yy] = *it;
      ll dist = abs(x[i] - xx) + abs(y[i] - yy);
      if (dist <= t[i] - tt) {
	rec.emplace(mnum-1, t[i], x[i], y[i]);
	ans = max(ans, -(mnum-1));
	break;
      }
      it++;

    }
  }
  cout << ans << endl;

  return 0;
}

