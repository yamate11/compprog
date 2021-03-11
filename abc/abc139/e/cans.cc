#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

class MyException : public exception {};

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(N-1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-1; j++) {
      int x; cin >> x; x--;
      A.at(i).at(j) = x;
    }
  }
  auto enc = [&](int x, int y) {
    if (x > y) swap(x, y);
    return x * N + y;
  };
  vector<vector<int>> succ(N*N);
  auto reg = [&](int x, int y, int z) {
    int e1 = enc(x, y);
    int e2 = enc(x, z);
    succ.at(e1).push_back(e2);
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-2; j++) {
      reg(i, A.at(i).at(j), A.at(i).at(j+1));
    }
  }
  vector<int> visited(N*N, -1);
  function<int(int,int)> dfs = [&](int e, int p) {
    int r = visited.at(e);
    if (r >= 0) return r;
    if (r == -2) throw MyException();
    visited.at(e) = -2;
    int len = 0;
    for (int c : succ.at(e)) {
      if (c == p) continue;
      int z = dfs(c, e);
      len = max(len, z);
    }
    visited.at(e) = len + 1;
    return (len + 1);
  };
  int ans = 0;
  try {
    for (int i = 0; i < N; i++) {
      int z = dfs(enc(i, A.at(i).at(0)), -1);
      ans = max(ans, z);
    }
  }catch (const MyException& e) {
    ans = -1;
  }

  cout << ans << endl;

  return 0;
}

