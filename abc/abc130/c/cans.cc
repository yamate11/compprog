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

ll W, H, x, y;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> W >> H >> x >> y;
  double answer = (double)W * ((double)H / 2.0);
  int ans2;
  if (2 * x == W && 2 * y == H) {
    ans2 = 1;
  }else {
    ans2 = 0;
  }
  cout << answer << " " << ans2 << endl;

  return 0;
}

