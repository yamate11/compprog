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

enum Mode { Begin, AfterB };
string s;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> s;
  ll cnt = 0;
  ll acca = 0;
  Mode mode = Begin;
  for (size_t i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A') {
      if (mode == AfterB) {
	acca = 1;
      }else {
	acca++;
      }
      mode = Begin;
    }else if (s.at(i) == 'B') {
      if (mode == AfterB) {
	acca = 0;
      }
      mode = AfterB;
    }else if (s.at(i) == 'C') {
      if (mode == AfterB) {
	cnt += acca;
      }else {
	acca = 0;
      }
      mode = Begin;
    }
  }
  cout << cnt << endl;
  return 0;
}

