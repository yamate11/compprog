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

int N, A, B, C, D;
string s;

bool check() {
  if (C < D) {
    for (int i = A; i < C; i++) {
      if (s.at(i) == '#' && s.at(i+1) == '#') return false;
    }
    for (int i = B; i < D; i++) {
      if (s.at(i) == '#' && s.at(i+1) == '#') return false;
    }
    return true;
  }else {
    for (int i = A; i < C; i++) {
      if (s.at(i) == '#' && s.at(i+1) == '#') return false;
    }
    for (int i = B; i <= D; i++) {
      if (s.at(i-1) == '.' && s.at(i) == '.' && s.at(i+1) == '.')  return true;
    }
    return false;
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> A >> B >> C >> D >> s;
  A--;
  B--;
  C--;
  D--;
  cout << (check() ? "Yes" : "No") << endl;

  return 0;
}

