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

ll N, M;
vector<ll> vecA;

bool sat(ll m) {
  ll left = 2*m;
  ll right = 2*N - 1;
  while (left < right) {
    if (vecA.at(left) + vecA.at(right) < M)  return false;
    left ++;
    right --;
  }
  return true;
}

ll binsch(ll l, ll r) {
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (sat(mid))  r = mid;
    else           l = mid;
  }
  return r;
}

ll calc(ll left, ll right, ll shift, ll res) {
    while (left < right) {
      ll v = vecA.at(left) + vecA.at(right) - shift;
      DLOG("v %lld", v);
      if (res < v)  res = v;
      left++;
      right--;
    }
    return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  /*
  cin.tie(0);
  cout.tie(0);
  */
  cin >> N >> M;
  vecA.resize(2*N);
  for (ll i = 0; i < 2*N; i++)  cin >> vecA.at(i);
  sort(vecA.begin(), vecA.end());
  ll border = binsch(-1, N);
  DLOG("border %lld\n", border);
  ll ans = calc(0, 2*border-1, 0, 0);
  ans = calc(2*border, 2*N-1, M, ans);
  cout << ans << endl;
  
  return 0;
}

