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
  cout << setprecision(20);

  ll N, L;
  cin >> N >> L;

  ll sum = (2 * L + N - 1) * N / 2;
  ll answer;
  if (0 < L) {
    answer = sum - L;
  }else if (L + N - 1 < 0) {
    answer = sum - (L + N - 1);
  }else {
    answer = sum;
  }
  cout << answer << endl;

  return 0;
}

