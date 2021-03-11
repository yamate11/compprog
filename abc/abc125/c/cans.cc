#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 1

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

int gcd(int x, int y) {
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  int z = x % y;
  return gcd(y, z);
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  vector<int> left(N), right(N);
  left.at(0) = a.at(0);
  right.at(0) = a.at(N-1);
  for (int i = 1; i < N; i++) {
    left.at(i) = gcd(left.at(i-1), a.at(i));
    right.at(i) = gcd(right.at(i-1), a.at(N-1-i));
  }
  int val = max(left.at(N-2), right.at(N-2));
  for (int i = 0; i <= N-3; i++) {
    val = max(val, gcd(left.at(i), right.at(N-3-i)));
  }
  cout << val << endl;
  return 0;
}

