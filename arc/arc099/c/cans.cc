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

ll N, K;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;
  ll ans = 1 + ((N-K) + (K-2)) / (K-1);
  cout << ans << endl;

  return 0;
}

