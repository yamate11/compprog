#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

constexpr ll maxN = 200000;
ll N;
ll v[2][maxN];
vector<ll> vLeft, vRight;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  ll bMax = 0;
  ll sMax = 0;
  ll bMin = 1e10;
  ll sMin = 1e10;
  ll bIdx = -1;
  ll sIdx = -1;
  for (ll i = 0; i < N; i++) {
    cin >> v[0][i] >> v[1][i];
    if (v[0][i] > v[1][i]) swap(v[0][i], v[1][i]);
    bMax = max(bMax, v[1][i]);
    bMin = min(bMin, v[1][i]);
    sMax = max(sMax, v[0][i]);
    sMin = min(sMin, v[0][i]);
    if (bMax == v[1][i]) bIdx = i;
    if (sMin == v[0][i]) sIdx = i;
  }
  ll cand1 = (bMax - bMin) * (sMax - sMin);
  ll cand2;
  if (bIdx == sIdx) cand2 = cand1;
  else {
    ll safeL = min(v[0][bIdx], v[1][sIdx]);
    ll safeR = max(v[0][bIdx], v[1][sIdx]);
    DLOG("safeL = %lld, safeR = %lld", safeL, safeR);
    for (ll i = 0; i < N; i++) {
      if (v[1][i] < safeL) safeL = v[1][i];
      if (safeR < v[0][i]) safeR = v[0][i];
    }
    DLOG("safeL = %lld, safeR = %lld", safeL, safeR);
    for (ll i = 0; i < N; i++) {
      if ((safeL <= v[0][i] && v[0][i] <= safeR) ||
	  (safeL <= v[1][i] && v[1][i] <= safeR)   ) continue;
      vLeft.push_back(v[0][i]);
      vRight.push_back(v[1][i]);
    }
    ll k = vLeft.size();
    DLOG("k = %lld", k);
    if (k == 0) {
      cand2 = safeR - safeL;
    }else {
      vector<ll> order(k);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(),
	   [](ll a, ll b){ return vRight[a] > vRight[b]; });
      ll leftB = safeL;
      cand2 = 1e10;
      for (ll i = 0; i < k; i++) {
	cand2 = min(cand2, vRight[order[i]] - leftB);
	leftB = min(leftB, vLeft[order[i]]);
      }
      cand2 = min(cand2, safeR - leftB);
    }
    cand2 *= bMax - sMin;
  }
  cout << min(cand1, cand2) << endl;

  return 0;
}

