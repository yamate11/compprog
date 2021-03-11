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

ll N, K;
string S;
vector<ll> one, zero;

void s_cnt(ll& res, ll& idx, char req) {
  DLOG("IN: s_cnt(%lld, %lld, %c)\n", res, idx, req);
  res = 0;
  while (idx < N && S.at(idx) == req) {
    idx++;
    res++;
  }
  DLOG("OUT: s_cnt: res = %lld, idx = %lld\n", res, idx);
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K >> S;
  DLOG("S = %s\n", S.c_str());
  ll idx = 0;
  ll i = 0;
  one.resize(N+1);
  zero.resize(N+1);
  while (idx < N) {
    s_cnt(one.at(i),  idx, '1');
    s_cnt(zero.at(i), idx, '0');
    DLOG("zero.at(%lld) = %lld; idx = %lld\n", i, zero.at(i), idx);
    i++;
  }
  DLOG("there\n");
  one.at(i) = zero.at(i) = 0;
  ll intvSize = i + 1;
  ll val = 0;
  for (ll i = 0; i < min(K, intvSize); i++) {
    val += one.at(i) + zero.at(i);
  }
  if (K < intvSize)  val += one.at(K);
  ll ans = val;
  for (ll i = K; i < intvSize - 1; i++) {
    ll diff = zero.at(i) + one.at(i+1) - (one.at(i-K) + zero.at(i-K));
    val += diff;
    ans = max(ans, val);
  }
  cout << ans << endl;
  

  return 0;
}

