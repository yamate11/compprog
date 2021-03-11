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

ll P, Q, R;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> P >> Q >> R;
  ll m = max(P, Q);
  m = max(m, R);
  ll ans = P + Q + R - m;
  cout << ans << endl;
  
  

  return 0;
}

