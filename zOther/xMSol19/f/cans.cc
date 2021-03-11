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

int N;
vector<vector<char>> A;
vector<bool> visited;

void dfs(int x) {
  if (visited.at(x)) return;
  visited.at(x) = true;
  for (int i = 1; i <= N; i++) {
    if ((i < x && A.at(x).at(i) == 0) || (x < i && A.at(i).at(x) == 1)) {
      dfs(i);
    }
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  A.resize(N+1);
  for (int i = 2; i <= N; i++) {
    A.at(i).resize(N+1);
    string line;
    cin >> line;
    for (int j = 1; j < i; j++) {
      A.at(i).at(j) = line.at(j-1) == '0' ? 0 : 1;
    }
  }
  int winner = 1;
  for (int i = 2; i <= N; i++) {
    if (A.at(i).at(winner)) winner = i;
  }
  visited.resize(N+1);
  dfs(winner);
  int cnt = 0;
  for (int i = 0; i <= N; i++) if (visited.at(i)) cnt++;
  cout << cnt << endl;

  return 0;
}

