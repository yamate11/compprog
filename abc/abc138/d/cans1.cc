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

vector<vector<int>> nbr;
vector<int> added;
vector<int> val;

void dfs(int n, int parent, int acc) {
  acc += added.at(n);
  val.at(n) = acc;
  for (int c : nbr.at(n)) {
    if (c == parent) continue;
    dfs(c, n, acc);
  }
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

  int N, Q; cin >> N >> Q;
  nbr.resize(N+1);
  added.resize(N+1);
  val.resize(N+1);
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  for (int i = 0; i < Q; i++) {
    int p, x; cin >> p >> x;
    added.at(p) += x;
  }
  dfs(1, -1, 0);
  for (int i = 1; i <= N; i++) {
    if (i > 1) cout << " ";
    cout << val.at(i);
  }
  cout << endl;

  return 0;
}

