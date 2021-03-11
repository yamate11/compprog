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
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
typedef pair<double, int> Pair;

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

  ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
  int N; cin >> N;
  vector<int> X(N+2), Y(N+2), R(N+2);
  X.at(0) = xs; Y.at(0) = ys; R.at(0) = 0;
  X.at(N+1) = xt; Y.at(N+1) = yt; R.at(N+1) = 0;
  for (int i = 1; i <= N; i++) {
    int x, y, r; cin >> x >> y >> r;
    X.at(i) = x; Y.at(i) = y; R.at(i) = r;
  }
  vector<double> eDist(N+2, LLONG_MAX);
  priority_queue<Pair, vector<Pair>, greater<Pair>> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    Pair p = que.top(); que.pop();
    double ed = p.first;
    int i = p.second;
    if (i == N+1) {
      cout << ed << endl;
      return 0;
    }
    if (eDist.at(i) <= ed) continue;
    eDist.at(i) = ed;
    for (int j = 0; j < N+2; j++) {
      if (i == j) continue;
      double xDiff = X.at(j) - X.at(i);
      double yDiff = Y.at(j) - Y.at(i);
      double cd = sqrt(xDiff*xDiff + yDiff*yDiff);
      double thisEd = max(0.0, cd - (R.at(i) + R.at(j)));
      if (ed + thisEd >= eDist.at(j)) continue;
      que.emplace(ed + thisEd, j);
    }
  }
  return 0;
}

