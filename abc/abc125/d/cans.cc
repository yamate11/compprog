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

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  ll N;
  cin >> N;
  ll sum = 0;
  char neg = 0;
  ll vMin = (ll)(1e10);
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    if (a < 0) {
      neg = 1 - neg;
      a = -a;
    }
    sum += a;
    vMin = min(vMin, a);
  }
  if (neg == 0) {
    cout << sum << endl;
  }else {
    cout << sum - 2*vMin << endl;
  }

  return 0;
}

