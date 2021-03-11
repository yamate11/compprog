#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  bool imp = false;

  // using StA = pair<ll, ll>;
  vector<map<ll, ll>> fc(2);
  fc.at(0)[-1] = M;
  fc.at(0)[N] = -1;
  fc.at(1)[-1] = M;
  fc.at(1)[N] = -1;

  auto sfunc = [&](ll type, ll sx) -> ll {
    if (type == 0) {
      auto it = fc.at(type).upper_bound(sx);
      it--;
      return it->second;
    }else {
      auto it = fc.at(type).lower_bound(sx);
      return it->second;
    }
  };

  auto sadd = [&](ll type, ll sx, ll sy) -> void {
    auto& mp = fc.at(type);
    if (type == 0) {
      auto it = mp.upper_bound(sx);
      it--;
      if (it->second <= sy) return;
      if (it->first < sx) it++;
      while (it->second >= sy) it = mp.erase(it);
      mp[sx] = sy;
    }else {
      auto it = mp.lower_bound(sx);
      if (it->second >= sy) return;
      if (it->first > sx) it--;
      while (it->second <= sy) {
	auto tmp = it--;
	mp.erase(tmp);
      }
      mp[sx] = sy;
    }
  };

  for (ll q = 0; q < Q; q++) {
    if (imp) {
      cout << "NO\n";
      continue;
    }
    ll x, y; cin >> x >> y; x--; y--;
    ll sx = x / 2;
    ll sy = y / 2;
    if (x % 2 == 0) {
      if (sfunc(1, sx) >= sy) {
	imp = true;
	cout << "NO\n";
	continue;
      }else {
	cout << "YES\n";
	sadd(0, sx, sy);
      }
    }else {
      if (sfunc(0, sx) <= sy) {
	imp = true;
	cout << "NO\n";
	continue;
      }else {
	cout << "YES\n";
	sadd(1, sx, sy);
      }
    }
  }
  return 0;
}

