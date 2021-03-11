#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
  string f11 = "What are you doing while sending \"";
  string f12 = "\"? Are you busy? Will you send \"";
  string f13 = "\"?";
  ll t0 = 75;
  ll t1 = 34;
  ll t2 = 32;
  ll t3 = 2;
  assert((ll)f0.size() == t0);
  assert((ll)f11.size() == t1);
  assert((ll)f12.size() == t2);
  assert((ll)f13.size() == t3);
  vector<ll> sz({t0});
  ll cur = t0;
  const ll lim = ll(1e18) + 100000;
  while (cur <= lim) {
    cur = t1 + cur + t2 + cur + t3;
    sz.push_back(cur);
  }
  ll ii = sz.size();
  ll szsz = ll(1e5) + 10;
  sz.resize(szsz);
  for (; ii < szsz; ii++) sz[ii] = cur;

  auto func = [&](auto rF, ll n, ll k) -> char {
    if (n == 0) {
      if (t0 <= k) return '.';
      return f0[k];
    }
    if (n < szsz && sz[n] <= k) return '.';
    if (k < t1) return f11[k];
    k -= t1;
    if (k < sz[n-1]) return rF(rF, n-1, k);
    k -= sz[n-1];
    if (k < t2) return f12[k];
    k -= t2;
    if (k < sz[n-1]) return rF(rF, n-1, k);
    k -= sz[n-1];
    if (k < t3) return f13[k];
    return '.';
  };

  auto solve = [&]() -> void {
    ll n, k; cin >> n >> k;
    cout << func(func, n, k - 1);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();
  cout << endl;

  return 0;
}

