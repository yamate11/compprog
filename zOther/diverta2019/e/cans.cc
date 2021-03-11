#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 1

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll bigP = (ll)(1e9+7);

ll N;
vector<ll> a;

ll funcNZ(ll k) {
  vector<vector <ll>> dp(2);
  dp.at(0).resize(k);
  dp.at(1).resize(k);
  dp.at(0).at(0) = 1;
  dp.at(1).at(0) = 0;
  for (ll i = 1; i < k; i++) {
    dp.at(0).at(i) = (dp.at(0).at(i-1) + 2 * dp.at(1).at(i-1)) % bigP;
    dp.at(1).at(i) = dp.at(0).at(i-1);
  }
  ll ans = dp.at(0).at(k-1) + dp.at(1).at(k-1);
  DLOG("funcNZ(%lld) = %lld\n", k, ans);
  return ans;
}

ll funcZ(ll k) {
  ll ret = 1;
  for (ll i = 0; i < k-1; i++) {
    ret = (2 * ret) % bigP;
  }
  DLOG("funcZ(%lld) = %lld\n", k, ret);
  return ret;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  a.resize(N);
  ll tot = 0;
  for (ll i = 0; i < N; i++)  {
    ll x;
    cin >> x;
    a.at(i) = x;
    tot = tot ^ x;
  }
  DLOG("tot = %lld\n", tot);

  vector<ll> zero;
  ll t = 0;
  for (ll i = 0; i < N; i++) {
    t = t ^ a.at(i);
    if (t == tot) {
      zero.push_back(i+1);
      t = 0;
    }
  }
  ll zsize = zero.size();
  DLOG("zsize = %lld\n", zsize);

  if (tot == 0) {
    ll t = 0;
    unordered_set<ll> common;
    for (ll i = 0; i < zero.at(0)-1; i++) {
      t = t ^ a.at(i);
      common.insert(t);
    }
    for (ll j = 1; j < zsize; j++) {
      t = 0;
      unordered_set<ll> cur;
      for (ll i = zero.at(j-1); i < zero.at(j)-1; i++) {
	t = t ^ a.at(i);
	if (common.count(t)) cur.insert(t);
      }
      common = cur;
    }
    ll csize = common.size();
    DLOG("csize = %lld\n", csize);
    ll only = funcZ(zsize);
    ll ans = (only + csize * (funcNZ(2*zsize) + bigP - only)) % bigP;
    cout << ans << endl;
  }else {
    cout << funcNZ(zsize) << endl;
  }

  return 0;
}

