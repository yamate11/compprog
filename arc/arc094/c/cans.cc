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

int A, B, C;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> A >> B >> C;
  if (A < B) swap(A, B);
  if (B < C) swap(B, C);
  if (A < B) swap(A, B);
  int answer;
  if ((B - C) % 2 == 0) {
    answer = (A - B) + (B - C) / 2;
  }else {
    answer = (A - B) + (B - C) / 2 + 2;
  }
  cout << answer << endl;

  return 0;
}

