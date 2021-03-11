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

typedef pair<int, int> Pair;

int N, M;
vector<vector<int>> nbr;
map<Pair, char> dir;
vector<bool> visited;

void mkDir(int x, int y) {
  dir[make_pair(x, y)] = 1;
  dir[make_pair(y, x)] = -1;
}

void dfs(int p, int c) {
  char parity = 0;
  if (visited.at(c)) {
    mkDir(p, c);
    return;
  }
  visited.at(c) = true;
  for (int g : nbr.at(c)) {
    if (g == p) continue;
    char d = dir[make_pair(c, g)];
    if (d == 0) {
      dfs(c, g);
      d = dir[make_pair(c, g)];
    }
    if (d == 1) parity = 1 - parity;
  }
  if (p >= 1) {
    if (parity) mkDir(c, p);
    else        mkDir(p, c);
  }
  return;
}

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

  cin >> N >> M;
  if (M % 2 == 1) {
    cout << "-1\n";
    return 0;
  }
  nbr.resize(N+1);
  visited.resize(N+1);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
    dir[make_pair(a,b)] = dir[make_pair(b,a)] = 0;
  }
  dfs(-1, 1);
  for (auto m : dir) {
    int x = m.first.first, y = m.first.second;
    char d = m.second;
    if (x > y) continue;
    if (d == 1) { cout << x << " " << y << "\n"; }
    else        { cout << y << " " << x << "\n"; }
  }

  return 0;
}

