#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll N, X, D;
vector<ll> vecM, vecP, vecW, vecK;
vector<vector <ll>> child;

// Note: this knapsack gets the lightest weight for each value.
vector<ll> knapsack(vector<ll> wt, vector<ll> val, vector<ll> num,
		    ll maxWt, ll maxVal) {

  DLOG("sizes of wt, val, num %ld, %ld, %ld\n", wt.size(), val.size(), num.size());
  vector<ll> mWt, mVal;
  for (ll i = 0; i < (ll) wt.size(); i++) {
    ll vi = 1;
    ll s = 0;
    while (s + vi < num.at(i)) {
      mWt.push_back(vi * wt.at(i));
      mVal.push_back(vi * val.at(i));
      s += vi;
      vi *= 2;
    }
    mWt.push_back((num.at(i) - s) * wt.at(i));
    mVal.push_back((num.at(i) - s) * val.at(i));
  }

  DLOG("sizes of mWt, mVal, %ld, %ld\n", mWt.size(), mVal.size());
  vector<ll> results(maxVal + 1, maxWt + 1);
  results.at(0) = 0;
  for (ll i = 0; i < (ll) mWt.size(); i++) {
    for (ll v = maxVal; v >= 1; v--) {
      ll v1 = v - mVal.at(i);
      if (v1 >= 0) {
	ll w0 = results.at(v);
	ll w1 = results.at(v1);
	if (w1 <= maxWt)  results.at(v) = min(w0, w1 + mWt.at(i));
      }
    }
  }
  return results;
}

void setW(ll node) {
  ll k = 1;
  ll w = vecM.at(node);
  for (auto x : child.at(node)) {
    setW(x);
    k += vecK.at(x);
    w += vecW.at(x);
  }
  vecK.at(node) = k;
  vecW.at(node) = w;
}

int main() {
#if DEBUG
#else
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> X >> D;
  vecM.resize(N+1);
  vecP.resize(N+1);
  cin >> vecM.at(1);
  child.resize(N+1);
  for (ll i = 2; i <= N; i++) {
    ll m, p;
    cin >> m >> p;
    vecM.at(i) = m;
    vecP.at(i) = p;
    child.at(p).push_back(i);
  }
  vecW.resize(N+1);
  vecK.resize(N+1);
  setW(1);

  vector<ll> num(N, min(N, D));
  num.at(0) = N;
  vector<ll> kp =
    knapsack(vector<ll>(vecW.begin() + 1, vecW.end()),
	     vector<ll>(vecK.begin() + 1, vecK.end()),
	     num, X, N*N*N);
  
  DLOG("kp returns\n");

  vector<ll> ord(N);
  for (ll i = 0; i < N; i++)  { ord.at(i) = i+1; }
  sort(ord.begin(), ord.end(),
       [](ll a, ll b) {
	 bool judge = (vecK.at(a) * vecW.at(b)) > (vecK.at(b) * vecW.at(a));
	 DLOG("judge: %lld, %lld --> %d ;; %lld, %lld, (%lld), %lld, %lld, (%lld)\n", a, b, judge, vecK.at(a), vecW.at(b), vecK.at(a)*vecW.at(b), vecK.at(b), vecW.at(a), vecK.at(b)*vecW.at(a));
	 return judge;
       });
  debug([ord]() { 
      for (ll i = 0; i < N; i++) {
	DLOG("ord[%lld] = %lld\n", i, ord.at(i));
      }
      for (ll i = 0; i < (ll) vecW.size(); i++) {
	DLOG("vecW[%lld] = %lld\n", i, vecW.at(i));
      }
    });

  DLOG("sort returns.\n");
  ll ans = 0;
  for (ll v = 0; v <= N*N*N; v++) {
    if (kp.at(v) == LLONG_MAX)  continue;
    if (kp.at(v) > X)  continue;
    DLOG("kp(%lld) = %lld\n", v, kp.at(v));
    ll rem = X - kp.at(v);
    ll num = v;
    for (ll j = 0; j < N; j++) {
      ll p = ord.at(j);
      ll lim = (p == 1) ? X : max(D-N, (ll)0);
      ll count = min(lim, rem / vecW.at(p));
      DLOG("    p == %lld, count == %lld, rem == %lld\n", p, count, rem);
      num += count * vecK.at(p);
      rem -= count * vecW.at(p);
    }
    DLOG("  num = %lld\n", num);
    ans = max(ans, num);
  }
  cout << ans << endl;

  return 0;
}

