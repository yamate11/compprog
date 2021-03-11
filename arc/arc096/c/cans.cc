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

ll A, B, C, X, Y;

ll cost(ll p, ll q, ll r) {
  return A * p + B * q + C * 2 * r;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> A >> B >> C >> X >> Y;
  
  if (X < Y) {
    swap(X, Y);
    swap(A, B);
  }
  ll ans = cost(0, 0, X);
  ans = min(ans, cost(X, Y, 0));
  ans = min(ans, cost(X-Y, 0, Y));
  cout << ans << endl;
  return 0;
}

