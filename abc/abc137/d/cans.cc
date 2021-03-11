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

  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++)  cin >> A.at(i) >> B.at(i);
  vector<int> ord(N);
  for (int i = 0; i < N; i++)  ord.at(i) = i;
  sort(ord.begin(), ord.end(),
       [&](int x, int y) { return A.at(x) < A.at(y); });
  priority_queue<int> que;
  int i = 0;
  int ans = 0;
  for (int d = 1; d <= M; d++) {
    while (i < N && A.at(ord.at(i)) <= d) {
      que.push(B.at(ord.at(i)));
      i++;
    }
    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << endl;

  return 0;
}

