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

  string S;
  cin >> S;
  vector<char> v;
  for (int i = 0; i < 4; i++) v.push_back(S.at(i));
  sort(v.begin(), v.end());
  if (v[0] == v[1] && v[2] == v[3] && v[1] != v[2]) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }

  return 0;
}

