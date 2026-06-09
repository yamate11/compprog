#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> vec;
    ll score = 0;

    auto nxt = [&](char c, ll i) -> ll {
      while (i < n && s[i] != c) i++;
      return i;
    };

    ll i = 0;
    ll j1 = nxt('W', i);
    ll start = j1 - i;
    ll end = 0;
    if (j1 == n) {
      if (k == 0) {
	cout << 0 << "\n";
      }else {
	cout << 2 * k - 1 << "\n";
      }
      return;
    }
    while (true) {
      ll j0 = nxt('L', j1);
      ll w = j0 - j1;
      score += 2 * w - 1;
      if (j0 == n) {
	end = 0;
	break;
      }
      j1 = nxt('W', j0);
      if (j1 == n) {
	end = j1 - j0;
	break;
      }
      vec.push_back(j1 - j0);
    }
    sort(vec.begin(), vec.end());
    ll vsz = vec.size();
    ll idx = 0;
    while (k > 0) {
      if (idx >= vsz) {
	break;
      }else {
	if (k < vec[idx]) {
	  score += 2 * k;
	  cout << score << "\n";
	  return;
	}else if (k == vec[idx]) {
	  score += 2 * k + 1;
	  cout << score << "\n";
	  return;
	}else {
	  score += 2 * vec[idx] + 1;
	  k -= vec[idx];
	}
	idx++;
      }
    }
    auto func = [&](ll len) -> void {
      if (k == 0) return;
      if (k < len) {
	score += 2 * k;
	k = 0;
      }else {
	score += 2 * len;
	k -= len;
      }
    };

    func(start);
    func(end);
    cout << score << "\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

