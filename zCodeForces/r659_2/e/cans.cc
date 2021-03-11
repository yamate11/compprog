#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, string& s1, string& s2) -> ll {
    vector cvt(20, vector(20, int8_t(false)));
    vector next(20, 0LL);
    for (ll i = 0; i < n; i++) {
      ll p = s1.at(i) - 'a';
      ll q = s2.at(i) - 'a';
      if (p != q) {
	cvt.at(p).at(q) = true;
	next.at(p) |= (1LL << q);
      }
    }

    auto dagsize = [&](ll x) -> ll {
      ll ret = 1;
      queue<ll> que;
      vector<int8_t> seen(1LL << 20);
      for (ll i = 0; i < 20; i++) {
	ll t = 1LL << i;
	if (t & x) que.push(t);
      }
      while (!que.empty()) {
	ll t = que.front(); que.pop();
	ll k = __builtin_popcountll(t);
	for (ll i = 0; i < 20; i++) {
	  ll q = 1LL << i;
	  if (!(q & x) || (q & t) || (next.at(i) & t) || (seen.at(t | q))) {
	    continue;
	  }
	  seen.at(t | q) = true;
	  que.push(t | q);
	  ret = max(ret, k + 1);
	}
      }
      return ret;
    };

    ll cid = 1;
    ll ans = 0;
    vector wc(20, 0LL);
    auto dfs = [&](const auto& rF, ll i) -> void {
      assert(wc.at(i) == 0 || wc.at(i) == cid);
      if (wc.at(i) == cid) return;
      wc.at(i) = cid;
      for (ll j = 0; j < 20; j++) {
	if (i == j || (!cvt.at(i).at(j) && !cvt.at(j).at(i))) continue;
	rF(rF, j);
      }
    };

    for (ll z = 0; z < 20; z++) {
      if (wc.at(z) > 0) continue;
      dfs(dfs, z);
      ll x = 0;
      ll size = 0;
      for (ll i = 0; i < 20; i++) {
	if (wc.at(i) == cid) {
	  x |= (1LL << i);
	  size++;
	}
      }
      if (size >= 2) ans += 2 * size - dagsize(x) - 1;
      cid++;
    }
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    cout << solve(n, s1, s2) << endl;
  }


  return 0;
}

