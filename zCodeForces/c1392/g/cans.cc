#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k; cin >> n >> m >> k;

  auto enc = [&](string x) -> ll {
    ll ret = 0;
    for (ll i = 0; i < k; i++) if (x[i] == '1') ret |= (1 << i);
    return ret;
  };

  string s, t; cin >> s >> t;
  ll es = enc(s);
  ll et = enc(t);
  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; i++) {
    ll aa, bb; cin >> aa >> bb; aa--; bb--;
    a[i] = aa;
    b[i] = bb;
  }

  auto appl = [&](const auto& f, ll e) -> ll {
    ll ret = 0;
    for (ll i = 0; i < k; i++) ret |= ((e >> i) & 1) << f[i];
    return ret;
  };

  vector<ll> f(k);
  iota(f.begin(), f.end(), 0);
  vector<ll> sidx(1LL << k, -1), tidx(1LL << k, -1);
  sidx[es] = n;
  tidx[et] = n;
  for (ll i = n-1; i >= 0; i--) {
    swap(f[a[i]], f[b[i]]);
    ll x = appl(f, es);
    sidx[x] = i;
    ll y = appl(f, et);
    if (tidx[y] < 0) tidx[y] = i;
  }

  for (ll x = (1LL << k) - 1; x >= 0; x--) {
    auto mymin = [](ll p, ll q) -> ll { return min(p, q); };
    auto mymax = [](ll p, ll q) -> ll { return max(p, q); };
    auto sub = [&](auto& vec, auto func) -> void {
      if (vec[x] >= 0) {
	for (ll j = 0; j < k; j++) {
	  if (x & (1LL << j)) {
	    ll y = x ^ (1LL << j);
	    if (vec[y] < 0) vec[y] = vec[x];
	    else            vec[y] = func(vec[y], vec[x]);
	  }
	}
      }
    };
    sub(sidx, mymin);
    sub(tidx, mymax);
  }

  ll common1 = -1;
  ll idxL = -1;
  ll idxR = -1;
  for (ll x = (1LL << k) - 1; x >= 0; x--) {
    if (sidx[x] >= 0 && tidx[x] >= 0 && tidx[x] - sidx[x] >= m) {
      ll cx = __builtin_popcountll(x);
      if (cx > common1) {
	common1 = cx;
	idxL = sidx[x] + 1;
	idxR = tidx[x];
      }
    }
  }

  ll s1 = __builtin_popcountll(es);
  ll t1 = __builtin_popcountll(et);
  ll common = k + 2 * common1 - (s1 + t1);
  cout << common << "\n" << idxL << " " << idxR << "\n";

  return 0;
}

