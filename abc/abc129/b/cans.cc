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

ll N;
vector<ll> W(101);
ll T;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  for (int i = 1; i <= N; i++)  cin >> W.at(i);
  ll ans = 100000;
  for (T = 1; T < N; T++) {
    ll S1 = 0;
    ll S2 = 0;
    for (int i = 1; i <= T; i++) {
      S1 += W.at(i);
    }
    for (int i = T+1; i <= N; i++) {
      S2 += W.at(i);
    }
    ll v = abs(S1 - S2);
    ans = min(ans, v);
  }
  cout << ans << endl;

  return 0;
}

