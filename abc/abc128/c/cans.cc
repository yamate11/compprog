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

ll N, M;
vector<ll> sw;
vector<ll> p;

ll bitCount(ll bits) {
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    if (bits & (1 << i)) cnt++;
  }
  return cnt;
}

bool check(ll mask) {
  for (ll i = 0; i < M; i++) {
    if (bitCount(mask & sw.at(i)) % 2 != p.at(i)) return false;
  }
  return true;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M;
  sw.resize(M);
  p.resize(M);
  for (ll i = 0; i < M; i++) {
    ll k;
    cin >> k;
    sw.at(i) = 0;
    for (ll j = 0; j < k; j++) {
      ll x;
      cin >> x;
      sw.at(i) |= 1 << (x-1);
    }
    DLOG("sw %lld = %lld", i, sw.at(i));
  }
  for (ll i = 0; i < M; i++) {
    cin >> p.at(i);
  }

  ll answer = 0;
  for (ll k = 0; k < (1 << N); k++) {
    if (check(k)) answer++;
  }
  cout << answer << endl;

  return 0;
}

