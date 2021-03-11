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

string s;
ll K;
set<string> cands;

void showcands() {
  for (auto it = cands.begin(); it != cands.end(); it++) {
    cerr << *it << "\n";
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> s >> K;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j <= (int)s.size()) {
	cands.insert(s.substr(i, j));
      }
    }
  }
  DCALL(showcands);
  auto it = cands.begin();
  for (int i = 0; i < K-1; i++) it++;
  cout << *it << endl;
  
  return 0;
}

